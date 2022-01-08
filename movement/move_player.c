/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:09:16 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 20:55:00 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_random_seed(t_vars *vars)
{
	vars->seed += 1;
	if (vars->seed > 7)
		vars->seed = 0;
}

void	count_steps(t_vars *vars)
{
	create_random_seed(vars);
	vars->player->steps += 1;
	printf("Steps taken: %d.\n", vars->player->steps);
}

void	move_player(t_vars *vars, int x, int y)
{
	int	portal;

	count_steps(vars);
	mlx_destroy_image(vars->mlx, vars->tile[x][y].img);
	portal = vars->player->conditions->portal;
	if (portal == 2)
	{
		print_evolve_message(vars);
		printf("You Won.\n");
		exit (0);
	}
	if (vars->player->conditions->evolve)
		set_player_evolved(vars, x, y);
	else
		set_player_default(vars, x, y);
}

void	stay_player(t_vars *vars, int x, int y)
{
	if (!vars->player->conditions->evolve)
		set_player_default(vars, x, y);
	else if (vars->player->conditions->evolve)
		set_player_evolved(vars, x, y);
}

void	kill_player(t_vars *vars, int x, int y)
{
	char	id;

	id = vars->tile[x][y].id;
	mlx_destroy_image(vars->mlx, vars->tile[x][y].img);
	if (id == 'E' || id == '<' || id == '>')
		set_to_exit(vars, x, y);
	else
		set_to_floor(vars, x, y);
}
