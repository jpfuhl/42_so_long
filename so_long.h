/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:06:23 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/11 17:26:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

/*
**	is Player ...
**	on exit? evolved? finished collecting? direction of sight? staying?
*/

typedef struct s_player_conditions
{
	int		portal;
	int		evolve;
	int		all_items_collected;
	int		right;
	int		left;
	int		stay;
}	t_conditions;

/*
**	x|y coordinates of Player
**	# steps taken, # items collected 
**	->conditions of Player
*/

typedef struct s_player_data
{
	int				x;
	int				y;
	int				steps;
	int				items_collected;
	t_conditions	*conditions;
}	t_player;

/*
**	Counting each tile/sprite in the map while parsing:
**	# walls, # floors, # collectibles, # player, # exit
**	is count finished?
*/

typedef struct s_map_stats
{
	int		wall;
	int		floor;
	int		item;
	int		player;
	int		exit;
	int		count_finished;
}	t_stats;

/*
**	Each tile on the map is a point stored with data:
**
**	IDENTITY
**	default id:		{0,1,C,E,P}
**	modified id:	{l,L,<,r,R,>}
**	left:	default l, evolved L, on exit <
**	right:	default r, evolved R, on exit >
**
**	IMAGE LAYERS
**	img:		tile/sprite
**	portal:		exit
**	background:	floor tile
*/

typedef struct s_tile
{
	char	id;
	void	*img;
	void	*portal;
	void	*background;
}	t_tile;

/*
**	Collecting information about occurring errors.
*/

typedef struct s_error_status
{
	int	invalid_filename;
	int	memory_allocation_failed;
	int	empty_line;
	int	rectangular;
	int	invalid_char;
	int	borders;
	int	collectible;
	int	player;
	int	exit;
}	t_error;

/*
**	Storing all relevant data in one place.
**	Passing to every function.
**
**	x * y Dimensions of window (tile count)
**	seed to generate a "semi-random" number (dependent on step-count)
**	
**	minilibx:
**	mlx, window
*/

typedef struct s_game_variables
{
	int			x;
	int			y;
	int			seed;
	void		*mlx;
	void		*window;
	t_player	*player;
	t_stats		*stats;
	t_error		*error_status;
	t_tile		**tile;
}	t_vars;

/*
**	main.c:
*/

void	allocate_memory_for_structs(t_vars *vars);
void	exit_program_with_error(t_vars *vars);
int		close_window_x(t_vars *vars);

/*
**	initialise_structs.c:
**	Functions to set all struct variables to default (0)
*/

void	initialise_structs(t_vars *vars);
void	initialise_game_variables(t_vars *vars);
void	initialise_error_status(t_vars *vars);
void	initialise_map_stats(t_vars *vars);
void	initialise_player(t_vars *vars);

/*
**	parse_map.c:
**	Functions to convert map.ber into a 2D array of s_tile(s)
*/

void	parse_map(t_vars *vars, char **argv);
void	get_xy_dimensions(t_vars *vars, char **argv);
void	create_array_of_tiles(t_vars *vars);
void	process_map(t_vars *vars, char **argv);
void	set_tiles(t_vars *vars, char c, int x, int y);

/*
**	set_tiles.c:
**	Functions to initialise s_tile(s) (count, id, img)
*/

void	set_to_exit(t_vars *vars, int x, int y);
void	set_to_player_start(t_vars *vars, int x, int y);
void	set_to_item(t_vars *vars, int x, int y);
void	set_to_floor(t_vars *vars, int x, int y);
void	set_to_wall(t_vars *vars, int x, int y);

/*
**	validate_map.c:
**	Functions to check if map is valid
*/

void	validate_map(t_vars *vars);
void	check_if_ber(char *map);
void	check_borders(t_vars *vars);
void	check_asset_count(t_vars *vars);
void	check_length(t_vars *vars, char *line);

/*
**	place_tiles.c:
**	Functions to place each tile to the window
*/

void	place_tiles(t_vars *vars);
void	place_image(t_vars *vars, int x, int y);
void	*get_image(t_vars *vars, char *path);

/*
**	trigger_player_movement.c:
*/

int		get_keycode(int keycode, t_vars *vars);
void	move_vertical(t_vars *vars, int x, int y, int sign);
void	move_horizontal(t_vars *vars, int x, int y, int sign);
void	turn_player(t_vars *vars, int keycode);
void	set_direction(t_vars *vars, int sign);

/*
**	check_player_position.c:
*/

int		check_for_wall(t_vars *vars, int x, int y);
void	check_for_portal(t_vars *vars, int x, int y);
void	check_for_item(t_vars *vars, int x, int y);
void	print_evolve_message(t_vars *vars);

/*
**	move_player.c:
*/

void	kill_player(t_vars *vars, int x, int y);
void	stay_player(t_vars *vars, int x, int y);
void	move_player(t_vars *vars, int x, int y);
void	count_steps(t_vars *vars);
void	create_random_seed(t_vars *vars);

/*
**	set_player_movement_tiles.c:
**	Functions to assign specific player tiles
*/

void	set_player_default(t_vars *vars, int x, int y);
void	set_player_default_right(t_vars *vars, int x, int y);
void	set_player_default_left(t_vars *vars, int x, int y);
void	set_player_evolved(t_vars *vars, int x, int y);

#endif