/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 20:02:53 by jpfuhl            #+#    #+#             */
/*   Updated: 2021/11/12 17:15:35 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_if_ber(char *map)
{
	size_t	len;
	char	*extension;

	len = (size_t)ft_strlen(map);
	extension = ".ber";
	if (!ft_strnstr(map, extension, len))
	{
		printf("Error\nMap must be a valid .ber file.\n");
		exit (0);
	}
}
