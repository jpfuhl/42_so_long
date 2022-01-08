/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:58:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/11 13:09:39 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	initialise_player(t_vars *vars)
{
	vars->player->steps = 0;
	vars->player->items_collected = 0;
	vars->player->conditions->portal = 0;
	vars->player->conditions->evolve = 0;
	vars->player->conditions->all_items_collected = 0;
	vars->player->conditions->right = 0;
	vars->player->conditions->left = 0;
	vars->player->conditions->stay = 0;
}

void	initialise_map_stats(t_vars *vars)
{
	vars->stats->wall = 0;
	vars->stats->floor = 0;
	vars->stats->item = 0;
	vars->stats->player = 0;
	vars->stats->exit = 0;
	vars->stats->count_finished = 0;
}

void	initialise_error_status(t_vars *vars)
{
	vars->error_status->invalid_filename = 0;
	vars->error_status->memory_allocation_failed = 0;
	vars->error_status->empty_line = 0;
	vars->error_status->rectangular = 0;
	vars->error_status->invalid_char = 0;
	vars->error_status->borders = 0;
	vars->error_status->collectible = 0;
	vars->error_status->player = 0;
	vars->error_status->exit = 0;
}

void	initialise_game_variables(t_vars *vars)
{
	vars->x = 0;
	vars->y = 0;
	vars->seed = 0;
}

void	initialise_structs(t_vars *vars)
{
	initialise_game_variables(vars);
	initialise_error_status(vars);
	initialise_map_stats(vars);
	initialise_player(vars);
}
