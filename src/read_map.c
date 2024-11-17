/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:08:16 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/16 14:09:18 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_map(t_cube *cube)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(cube->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("\n probleme to open the map \n");
	cube->map.map = (char **)malloc(sizeof(char *) * (cube->map.y +1));
	if (!(cube->map.map))
		ft_error("\nerreur de alocation de memoire\n");
	line = ft_get_next_line(fd);
	if (!line)
		ft_error("\n line is empty \n");
	i = 0;
	while (i < cube->map.y)
	{
		cube->map.map[i] = line;
		line = ft_get_next_line(fd);
		i++;
	}
	cube->map.map[i] = NULL;
	close(fd);
}

void	check_perimeters(t_cube *cube)
{
	int	x;
	int	y;

	x = cube->map.x;
	y = cube->map.y;
	while (x--)
	{
		if (cube->map.map[0][x] != '1' ||
			cube->map.map[y - 1][x] != '1')
			ft_error("\nmap is not closed\n");
	}
	while (y--)
	{
		if (cube->map.map[y][0] != '1' ||
			cube->map.map[y][cube ->map.x - 1] != '1')
			ft_error("\nmap is not closed\n");
	}
}
void	check_caracs(t_cube *cube, int x, int y)
{
	if (cube->map.map[y][x] != '1' && cube->map.map[y][x] != '0'
		&& cube ->map.map[y][x] != '\n')
		ft_error("Existance of an invalid caracter");
}

void	count_thing(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (cube->map.map[y])
	{
		x = 0;
		while (cube->map.map[y][x])
		{
			if (cube->map.map[y][x] == 'N' || cube->map.map[y][x] == 'S'\
				||cube->map.map[y][x] == 'E' || cube->map.map[y][x] == 'W')
				cube->map.player++;
			else
				check_caracs(cube, x, y);
			x++;
		}
		y++;
	}
	if (cube->map.player != 1)
		ft_error("Invalid number of player");
}
