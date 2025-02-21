/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:30:49 by dangonz3          #+#    #+#             */
/*   Updated: 2025/02/21 12:10:46 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

void	c_error(char *str, t_cub *c)
{
	ft_printf("Error\n%s\n", str);
	mlx_close_window(c->mlx);
	free_memory(c);
	exit (EXIT_FAILURE);
}

void	c_close(t_cub *c)
{
	mlx_close_window(c->mlx);
	free_memory(c);
	exit(EXIT_SUCCESS);
}

void	free_memory(t_cub *c)
{
	if (c->mlx)
		mlx_terminate(c->mlx);
	if (c->parse_struct)
		free_content(c->parse_struct);
	if (c->wall_n)
		free_t_texture(c->wall_n);
	if (c->wall_s)
		free_t_texture(c->wall_s);
	if (c->wall_e)
		free_t_texture(c->wall_e);
	if (c->wall_w)
		free_t_texture(c->wall_w);
	if (c->door_t)
		free_t_texture(c->door_t);
	if (c->sprite_t)
		free_t_texture(c->sprite_t);
	if (c->rays)
		free(c->rays);
	if (c->doors)
		free(c->doors);
	if (c)
		free(c);
}

void	free_t_texture(t_texture *t)
{
	int	i;

	i = 0;
	while (i < t->height)
	{
		free(t->pixels[i]);
		i++;
	}
	free(t->pixels);
	free(t);
}
