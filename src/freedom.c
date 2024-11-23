/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:28:55 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/23 16:04:56 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_line(char *line, t_cube *cube)
{
	printf("Error parsing; wrong content\n");
	free(line);
	free_content(cube);
	exit(1);
}
void	free_content(t_cube *cube)
{
	int	idx;

	idx = 0;
	if (cube->north_texture)
		free(cube->north_texture);
	if (cube->south_texture)
		free(cube->south_texture);
	if (cube->west_texture)
		free(cube->west_texture);
	if (cube->east_texture)
		free(cube->east_texture);
	if (cube->map)
	{
		while (cube->map[idx])
		{
			free(cube->map[idx]);
			idx++;
		}
		free(cube->map);
	}
}