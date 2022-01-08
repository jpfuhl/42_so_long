/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_movement_tiles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:33:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 21:06:14 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_player_evolved(t_vars *vars, int x, int y)
{
	if (vars->player->conditions->right)
	{
		vars->tile[x][y].id = 'R';
		vars->tile[x][y].img = get_image(vars, "xpm/demon_right_evolved.xpm");
		vars->tile[x][y].portal = NULL;
		vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
	}
	else if (vars->player->conditions->left)
	{
		vars->tile[x][y].id = 'L';
		vars->tile[x][y].img = get_image(vars, "xpm/demon_left_evolved.xpm");
		vars->tile[x][y].portal = NULL;
		vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
	}
	vars->player->x = x;
	vars->player->y = y;
}

void	set_player_default_left(t_vars *vars, int x, int y)
{
	vars->tile[x][y].id = 'l';
	vars->tile[x][y].img = get_image(vars, "xpm/demon_left.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
	if (vars->player->conditions->portal)
	{
		vars->tile[x][y].id = '<';
		vars->tile[x][y].portal = get_image(vars, "xpm/exit.xpm");
	}	
}

void	set_player_default_right(t_vars *vars, int x, int y)
{
	vars->tile[x][y].id = 'r';
	vars->tile[x][y].img = get_image(vars, "xpm/demon_right.xpm");
	vars->tile[x][y].portal = NULL;
	vars->tile[x][y].background = get_image(vars, "xpm/floor.xpm");
	if (vars->player->conditions->portal)
	{
		vars->tile[x][y].id = '>';
		vars->tile[x][y].portal = get_image(vars, "xpm/exit.xpm");
	}
}

void	set_player_default(t_vars *vars, int x, int y)
{
	if (vars->player->conditions->right)
		set_player_default_right(vars, x, y);
	else if (vars->player->conditions->left)
		set_player_default_left(vars, x, y);
	vars->player->x = x;
	vars->player->y = y;
}

// set player default left and right :: split