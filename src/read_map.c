/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:08:16 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/23 16:08:22 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*line_verification(char *line)
{
	int		idx;
	char	*tmp;
	char	*content;

	idx = 2;
	while (line[++idx])
	{
		if (!space_verification(line[idx]))
			break ;
	}
	tmp = ft_substr(line, idx, ft_strlen(line) - idx);
	content = ft_strtrim(tmp, "\n");
	return (free(tmp), content);
}
