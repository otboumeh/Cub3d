/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:06:37 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/16 14:04:42 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../src/libft/libft.h"


typedef struct s_map
{
	char	**map;
	char	*path;
	int		x;
	int		y;
	int		player;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

typedef struct s_cube
{
	// mlx_t			*mlx;
	t_map		map;
	int				player_x;
	int				player_y;
	
	// double			time_initial;

	// int				map_axis_y; //copia + pega so_long no funciona con cube
	// char			**map; //copia + pega so_long no funciona con cube
	// int				map_bool; //copia + pega so_long no funciona con cube

	// char			*png_floor;
	// mlx_texture_t	*texture_floor;
	// mlx_image_t		*img_floor;
	
	// char			*png_wall;
	// mlx_texture_t	*texture_wall;	
	// mlx_image_t		*img_wall;

} t_cube;
void	check_extension(char *argv1, t_cube *cube);
void	get_len(t_cube *cube);
void	read_map(t_cube *cube);
void	check_perimeters(t_cube *cube);
void	check_caracs(t_cube *cube, int x, int y);
void	count_thing(t_cube *cube);
void	check_arg_number(int argc);
void	ft_error(char *message);

#endif