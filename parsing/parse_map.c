/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:17:17 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 21:25:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_tiles(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
		set_to_wall(vars, x, y);
	else if (c == '0')
		set_to_floor(vars, x, y);
	else if (c == 'C')
		set_to_item(vars, x, y);
	else if (c == 'P')
	{
		if (vars->stats->player < 1)
			set_to_player_start(vars, x, y);
		else
			set_to_floor(vars, x, y);
	}
	else if (c == 'E')
	{
		if (vars->stats->exit < 1)
			set_to_exit(vars, x, y);
		else
			set_to_floor(vars, x, y);
	}
	else
	{
		vars->error_status->invalid_char = 1;
		exit_program_with_error(vars);
	}
}

void	process_map(t_vars *vars, char **argv)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	line = "start";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		y = 0;
		while (line[y] != '\0')
		{
			set_tiles(vars, line[y], x, y);
			y++;
		}
		free(line);
		x++;
	}
	close (fd);
}

void	create_array_of_tiles(t_vars *vars)
{
	int	i;

	i = 0;
	vars->tile = malloc(vars->x * sizeof(t_tile *));
	if (!vars->tile)
	{
		vars->error_status->memory_allocation_failed = 1;
		exit_program_with_error(vars);
	}
	while (i < vars->x)
	{
		vars->tile[i] = malloc(vars->y * sizeof(t_tile));
		if (!vars->tile[i])
		{
			vars->error_status->memory_allocation_failed = 1;
			exit_program_with_error(vars);
		}
		i++;
	}
}

void	get_xy_dimensions(t_vars *vars, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		vars->error_status->invalid_filename = 1;
		exit_program_with_error(vars);
	}
	line = "start";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\0')
		{
			vars->error_status->empty_line = 1;
			exit_program_with_error(vars);
		}
		vars->x += 1;
		check_length(vars, line);
		free(line);
	}
	close (fd);
}

void	parse_map(t_vars *vars, char **argv)
{	
	get_xy_dimensions(vars, argv);
	create_array_of_tiles(vars);
	process_map(vars, argv);
	validate_map(vars);
}
