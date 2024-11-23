/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:47:40 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/23 14:35:25 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* This function verify line per line to verify the existance of the structure and send the information 
to the correspendent function if all struct is found start analizing the map if the variable flag is 
positif free the program */
int	parse_line(char *line, t_cube *cube)
{
	int	flag;

	flag = 0;
	if (!line)
		return (1);
	if (!flag && ft_strncmp("NO ", line, 3) == 0)
		cube->north_texture = line_verification(line);
	else if (!flag && ft_strncmp("SO ", line, 3) == 0)
		cube->south_texture = line_verification(line);
	else if (!flag && ft_strncmp("WE ", line, 3) == 0)
		cube->west_texture = line_verification(line);
	else if (!flag && ft_strncmp("EA ", line, 3) == 0)
		cube->east_texture = line_verification(line);
	else if (!flag && ft_strncmp("F ", line, 2) == 0)
		flag = parse_colors(line + 1, cube->floor_color);
	else if (!flag && ft_strncmp("C ", line, 2) == 0)
		flag = parse_colors(line + 1, cube->ceiling_color);
	else
		parse_map(line, cube);
	if (flag)
		free_line(line, cube);
	return (0);
}
