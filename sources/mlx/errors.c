/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:30:49 by dangonz3          #+#    #+#             */
/*   Updated: 2024/11/28 17:33:40 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	c_error(char *str, t_cub *c)
{
	ft_printf("%s\n", str);
	free_memory(c);
	exit (EXIT_FAILURE);
}

void	c_error_img(char *str, t_cub *c)
{
	ft_printf("Couldn't load image: %s\n", str);
	free_memory(c);
	exit (EXIT_FAILURE);
}
