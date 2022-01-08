/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:10:22 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/11 17:28:00 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_length(t_vars *vars, char *line)
{
	int	length;

	if (vars->y == 0)
	{
		vars->y = ft_strlen(line);
		return ;
	}
	length = ft_strlen(line);
	if (length != vars->y)
	{
		vars->error_status->rectangular = 1;
		exit_program_with_error(vars);
	}
}

void	check_asset_count(t_vars *vars)
{
	if (vars->stats->item < 1)
	{
		vars->error_status->collectible = 1;
		exit_program_with_error(vars);
	}
	if (vars->stats->player < 1)
	{
		vars->error_status->player = 1;
		exit_program_with_error(vars);
	}
	if (vars->stats->exit < 1)
	{
		vars->error_status->exit = 1;
		exit_program_with_error(vars);
	}
}

void	check_borders(t_vars *vars)
{
	t_tile	**point;
	int		i;
	int		j;

	point = vars->tile;
	i = 0;
	while (i < vars->y)
	{
		if (point[0][i].id != '1' || point[vars->x - 1][i].id != '1')
			vars->error_status->borders = 1;
		i++;
	}
	j = 0;
	while (j < vars->x)
	{
		if (point[j][0].id != '1' || point[j][vars->y - 1].id != '1')
			vars->error_status->borders = 1;
		j++;
	}
	if (vars->error_status->borders)
		exit_program_with_error(vars);
}

void	validate_map(t_vars *vars)
{
	check_borders(vars);
	check_asset_count(vars);
}
