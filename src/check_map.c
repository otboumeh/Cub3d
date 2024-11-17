/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:35:49 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/16 14:08:15 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

void	check_extension(char *argv1, t_cube *cube)
{
	int	i;

	i = ft_strlen(argv1);
	if (ft_strncmp(&argv1[i - 4], ".cub", 4) != 0)
	{
		ft_error("\nError\n Map file must have .cub extension \n");
	}
	cube->map.path = argv1;
}
void	get_len(t_cube *cube)
{
	char	*line;
	char	*temp;
	int		fd;

	fd = open (cube->map.path, O_RDONLY);
	if (fd < 0)
		ft_error("\nprobleme to open the map\n");
	line = ft_get_next_line(fd);
	if (!line)
		ft_error("\nempty Map\n");
	cube->map.x = ft_strlen(line) - 1;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != cube->map.x)
			ft_error("\nMap is irregular on x\n");
		cube->map.y++;
		temp = line;
		line = ft_get_next_line(fd);
		free(temp);
	}
	close(fd);
}

void	ft_error(char *message)
{
	ft_printf("%s", message);
	exit(1);
}
