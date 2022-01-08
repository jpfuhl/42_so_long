/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:08:38 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/11 13:10:22 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program_with_error(t_vars *vars)
{
	char	*error_warning;

	error_warning = "Error\n";
	if (vars->error_status->invalid_filename)
		printf("%sPassed map does not exist.\n", error_warning);
	if (vars->error_status->memory_allocation_failed)
		printf("%sMemory allocation failed.\n", error_warning);
	if (vars->error_status->empty_line)
		printf("%sMap must not contain empty lines.\n", error_warning);
	if (vars->error_status->rectangular)
		printf("%sMap must be rectangular.\n", error_warning);
	if (vars->error_status->invalid_char)
		printf("%sMap must contain only {0,1,E,C,P}.\n", error_warning);
	if (vars->error_status->borders)
		printf("%sMap borders must be WALLS {1}.\n", error_warning);
	if (vars->error_status->collectible)
		printf("%sMap must contain atleast 1 ITEM.\n", error_warning);
	if (vars->error_status->player)
		printf("%sMap must contain atleast 1 PLAYER.\n", error_warning);
	if (vars->error_status->exit)
		printf("%sMap must contain atleast 1 EXIT.\n", error_warning);
	exit (0);
}

int	close_window_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	printf("DO NOT LEAVE ME.. BEHIND!! GRAARH!!\nYou Lost.\n");
	exit (0);
}

void	allocate_memory_for_structs(t_vars *vars)
{
	vars->error_status = malloc(sizeof(t_error));
	if (!vars->error_status)
	{
		printf("Error\nMemory allocation failed.\n");
		exit (0);
	}
	vars->player = malloc(sizeof(t_player));
	vars->stats = malloc(sizeof(t_stats));
	if (!vars->player || !vars->stats)
	{
		printf("Error\nMemory allocation failed.\n");
		exit (0);
	}	
	vars->player->conditions = malloc(sizeof(t_conditions));
	if (!vars->player->conditions)
	{
		printf("Error\nMemory allocation failed.\n");
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments passed.\n");
		exit (0);
	}
	check_if_ber(argv[1]);
	allocate_memory_for_structs(&vars);
	initialise_structs(&vars);
	vars.mlx = mlx_init();
	parse_map(&vars, argv);
	vars.window = mlx_new_window(vars.mlx, vars.y * 64, vars.x * 64, "so_long");
	place_tiles(&vars);
	mlx_key_hook(vars.window, get_keycode, &vars);
	mlx_hook(vars.window, 17, 1L << 17, close_window_x, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
