/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:08:01 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/10/21 22:40:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_image(t_vars *vars, char *path)
{
	int		pos[2];
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path, &pos[0], &pos[1]);
	return (img);
}

void	place_image(t_vars *vars, int x, int y)
{
	void	*mlx;
	void	*window;
	void	*img;
	void	*portal;
	void	*background;

	mlx = vars->mlx;
	window = vars->window;
	img = vars->tile[x][y].img;
	portal = vars->tile[x][y].portal;
	background = vars->tile[x][y].background;
	if (background)
		mlx_put_image_to_window(mlx, window, background, 64 * y, 64 * x);
	if (portal)
		mlx_put_image_to_window(mlx, window, portal, 64 * y, 64 * x);
	mlx_put_image_to_window(mlx, window, img, 64 * y, 64 * x);
}

/*
**	For "real-time" map visualization in shell, add following code:
**
**	in line 66:		printf("%c", vars->tile[i][j].id);
**
**	in line 68:		printf("\n");
**
**	in line 70:		printf("\n");
*/

void	place_tiles(t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < vars->x)
	{
		j = 0;
		while (j < vars->y)
		{
			place_image(vars, i, j);
			j++;
		}
		i++;
	}
	vars->stats->count_finished = 1;
}
