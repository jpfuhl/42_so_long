/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:32:59 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/05 21:09:52 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_evolve_message(t_vars *vars)
{
	char	*message[8];

	message[0] = "READY TO SET THE WORLD ON FIRE??";
	message[1] = "GRAARGH!!";
	message[2] = "NO MORE CAGES!!";
	message[3] = "NO PRISON CAN HOLD ME... NOW!!";
	message[4] = "AT LAST.. I AM.. FREE!!";
	message[5] = "AFTER MILLENIA.. I AM FREE!!";
	message[6] = "MY FIRE WILL CLEANSE THE WORLD!!";
	message[7] = "BURN!! AHAHAHA!!";
	printf("%s\n", message[vars->seed]);
}

void	check_for_item(t_vars *vars, int x, int y)
{
	if (vars->tile[x][y].id == 'C')
	{
		vars->player->items_collected += 1;
		printf("Items collected: %d.\n", vars->player->items_collected);
	}
	if (vars->player->items_collected == vars->stats->item)
	{
		vars->player->conditions->all_items_collected = 1;
		vars->player->conditions->evolve = 1;
		print_evolve_message(vars);
	}
}

void	check_for_portal(t_vars *vars, int x, int y)
{
	char	id;

	id = vars->tile[x][y].id;
	if (id == 'E' && !vars->player->conditions->all_items_collected)
		printf("YOU SHALL NOT PASS!!\n");
	if (id == 'E' || id == '<' || id == '>')
	{
		if (vars->player->conditions->all_items_collected)
		{
			vars->player->conditions->portal = 2;
			return ;
		}
		else
		{
			vars->player->conditions->portal = 1;
			return ;
		}
	}
	vars->player->conditions->portal = 0;
}

int	check_for_wall(t_vars *vars, int x, int y)
{
	if (vars->tile[x][y].id == '1')
		return (1);
	return (0);
}
