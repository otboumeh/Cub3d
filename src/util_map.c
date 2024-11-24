/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:54:40 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/24 14:24:59 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	delete_tab(char ***map, int i)
{
	int		j;
	char	*new_line;
	char	*tmp;
	char	*to_append;

	while ((*map)[++i])
	{
		new_line = ft_strdup("");
		j = -1;
		while ((*map)[i][++j])
		{
			if ((*map)[i][j] == '\t')
				to_append = ft_strdup("    ");
			else
				to_append = ft_sprintf("%c", (*map)[i][j]);
			tmp = ft_strdup(new_line);
			free(new_line);
			new_line = ft_sprintf("%s%s", tmp, to_append);
			free(tmp);
			free(to_append);
		}
		free((*map)[i]);
		(*map)[i] = new_line;
	}
}
