/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangonz3 <dangonz3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:21:58 by dangonz3          #+#    #+#             */
/*   Updated: 2025/02/21 16:25:13 by dangonz3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

void	ray_render(t_cub *c)
{
	int		index_ray;
	t_ray	*r;

	index_ray = 0;
	while (index_ray < NUM_RAYS)
	{
		r = &c->rays[index_ray];
		init_data_render(c, r);
		render(c, r);
		draw_wall_strip(c, index_ray);
		index_ray++;
	}
}

int	init_data_render(t_cub *c, t_ray *r)
{
	if (r->distance == 0)
		r->distance = 0.1;
	r->perp_distance = r->distance * cos(r->rayangle - c->p_rotationangle);
	r->distance_proj_plane = (WIN_WIDTH / 2) / tan(c->p_fov / 2);
	r->wall_strip_height = (TILE_SIZE / r->perp_distance) * \
	r->distance_proj_plane;
	r->wall_top_pixel = (WIN_HEIGHT / 2) - (r->wall_strip_height / 2);
	r->wall_bottom_pixel = (WIN_HEIGHT / 2) + (r->wall_strip_height / 2);
	return (0);
}

void	render(t_cub *c, t_ray *r) //identificamos la direccion cardinal del muro, y le adjudicamos su textura correspondiente
{	
	if (!r->was_hit_vertical)
	{
		if (r->im_door)
		{
			if (r->rayangle < PI && r->rayangle > 0) //DOOR
				calculate_wall_strip(c, r, c->door_t, TILE_SIZE - 1 - ((int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE)); //muro norte, el rayo viene desde arriba
			else
				calculate_wall_strip(c, r, c->door_t, (int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE); //muro sur
		}
		else if (r->rayangle < PI && r->rayangle > 0)
			calculate_wall_strip(c, r, c->wall_s, TILE_SIZE - 1 - ((int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE)); //muro sur, el rayo viene desde abajo
		else
			calculate_wall_strip(c, r, c->wall_n, (int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE); //muro norte
	}
	else
		render_aux(c, r);
}

void	render_aux(t_cub *c, t_ray *r)
{
	if (r->im_door)
	{
		if (r->rayangle > PI * 1 / 2 && r->rayangle < PI * 3 / 2) //DOOR
			calculate_wall_strip(c, r, c->door_t, TILE_SIZE - 1 - ((int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE)); //muro oeste, el rayo viene desde la derecha
		else //DOOR
			calculate_wall_strip(c, r, c->door_t, (int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE); //muro este
	}
	else if (r->rayangle > PI * 1 / 2 && r->rayangle < PI * 3 / 2)
		calculate_wall_strip(c, r, c->wall_w, TILE_SIZE - 1 - ((int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE)); //muro oeste, el rayo viene desde la derecha
	else 
		calculate_wall_strip(c, r, c->wall_e, (int)(r->wall_hit_x + r->wall_hit_y) % TILE_SIZE); //muro este
}

void	calculate_wall_strip(t_cub *c, t_ray *r, t_texture *t, int x)
{
	int	y;
	int	anti_y;
	int	img_x;
	int	img_y;

	y = 0;
	while (y < r->wall_top_pixel)
		c->strip[y++] = c->ceiling;
	img_x = 1;
	if (x != 1)
		img_x = (x * t->width) / TILE_SIZE;
	anti_y = y;
	if (r->wall_top_pixel < 0)
		anti_y += r->wall_top_pixel;
	while (y < r->wall_bottom_pixel && y < WIN_HEIGHT)
	{
		img_y = ((y - anti_y) * t->height) / (r->wall_bottom_pixel - r->wall_top_pixel);
		if ((r->im_door && c->doors[r->door_number].is_closed && 
		c->doors[r->door_number].opening))
			c->strip[y++] = WHITE;
		else if (img_y >= 0 && img_y < t->height && img_x >= 0 && img_x < t->width)
			c->strip[y++] = t->pixels[img_y][img_x];
	}
	while (y < WIN_HEIGHT)
		c->strip[y++] = c->floor;
}
