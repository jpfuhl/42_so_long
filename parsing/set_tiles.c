/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tiles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:21:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/10/21 22:40:07 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_to_exit(t_vars *vars, int x, int y)
{
	if (vars->stats->count_finished == 0)
		vars->stats->exit += 1;
	vars->tile[x][y].id = 'E';
	vars->tile[x][y].img = get_image(vars, "xpm/exit.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
}

void	set_to_player_start(t_vars *vars, int x, int y)
{
	if (vars->stats->count_finished == 0)
		vars->stats->player += 1;
	vars->player->conditions->right = 1;
	vars->tile[x][y].id = 'P';
	vars->tile[x][y].img = get_image(vars, "xpm/demon_right.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
	vars->player->x = x;
	vars->player->y = y;
}

void	set_to_item(t_vars *vars, int x, int y)
{
	if (vars->stats->count_finished == 0)
		vars->stats->item += 1;
	vars->tile[x][y].id = 'C';
	vars->tile[x][y].img = get_image(vars, "xpm/item.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
}

void	set_to_floor(t_vars *vars, int x, int y)
{
	if (vars->stats->count_finished == 0)
		vars->stats->floor += 1;
	vars->tile[x][y].id = '0';
	vars->tile[x][y].img = get_image(vars, "xpm/floor.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = NULL;
}

void	set_to_wall(t_vars *vars, int x, int y)
{
	if (vars->stats->count_finished == 0)
		vars->stats->wall += 1;
	vars->tile[x][y].id = '1';
	vars->tile[x][y].img = get_image(vars, "xpm/wall.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = NULL;
}
