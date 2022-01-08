/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_player_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:28:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 21:10:10 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_direction(t_vars *vars, int sign)
{
	if (sign == -1)
	{
		vars->player->conditions->right = 0;
		vars->player->conditions->left = 1;
	}
	else if (sign == 1)
	{
		vars->player->conditions->right = 1;
		vars->player->conditions->left = 0;
	}
}

void	turn_player(t_vars *vars, int keycode)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	if (keycode == 12)
	{
		vars->player->conditions->stay = 1;
		move_horizontal(vars, x, y, -1);
	}
	else if (keycode == 14)
	{
		vars->player->conditions->stay = 1;
		move_horizontal(vars, x, y, 1);
	}
}

void	move_horizontal(t_vars *vars, int x, int y, int sign)
{
	int	stay;

	stay = vars->player->conditions->stay;
	set_direction(vars, sign);
	if (!check_for_wall(vars, x, y + sign) && !stay)
	{
		if (!vars->player->conditions->all_items_collected)
			check_for_item(vars, x, y + sign);
		check_for_portal(vars, x, y + sign);
		kill_player(vars, x, y);
		move_player(vars, x, y + sign);
		place_tiles(vars);
	}
	else if (check_for_wall(vars, x, y + sign) || stay)
	{
		mlx_destroy_image(vars->mlx, vars->tile[x][y].img);
		check_for_portal(vars, x, y);
		stay_player(vars, x, y);
		place_tiles(vars);
	}
}

void	move_vertical(t_vars *vars, int x, int y, int sign)
{
	if (!check_for_wall(vars, x + sign, y))
	{
		if (!vars->player->conditions->all_items_collected)
			check_for_item(vars, x + sign, y);
		check_for_portal(vars, x + sign, y);
		kill_player(vars, x, y);
		move_player(vars, x + sign, y);
		place_tiles(vars);
	}
	else
	{
		mlx_destroy_image(vars->mlx, vars->tile[x][y].img);
		check_for_portal(vars, x, y);
		stay_player(vars, x, y);
		place_tiles(vars);
	}
}

int	get_keycode(int keycode, t_vars *vars)
{
	int	x;
	int	y;

	x = vars->player->x;
	y = vars->player->y;
	vars->player->conditions->stay = 0;
	if (keycode == 13)
		move_vertical(vars, x, y, -1);
	else if (keycode == 1)
		move_vertical(vars, x, y, 1);
	else if (keycode == 0)
		move_horizontal(vars, x, y, -1);
	else if (keycode == 2)
		move_horizontal(vars, x, y, 1);
	else if (keycode == 12 || keycode == 14)
		turn_player(vars, keycode);
	else if (keycode == 53)
	{
		printf("DO NOT.. LEAVE ME.. BEHIND!! GRAARH!!\nYou Lost.\n");
		exit (0);
	}
	return (0);
}
