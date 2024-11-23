/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:06:37 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/23 16:11:41 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../src/libft/libft.h"



typedef struct s_player_position
{
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
}			t_player_position;

typedef struct s_cube
{
	// mlx_t			*mlx;
	char		**map;
	int				player_x;
	int				player_y;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
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
//parsing.c
int		parse_line(char *line, t_cube *cube);
//check_map.c
void	check_extension(char *argv1, t_cube *cube);
int		read_file(char *file, t_cube *cube);


//freedom.c
void	error_line(char *line, t_cube *cube);
void	free_content(t_cube *cube);

//main.c
void	check_arg_number(int argc);
int		verification_start(t_cube *cube,\
			t_player_position *player_position, char **argv);

//read_map.c
char	*line_verification(char *line);

//utils.c
int		space_verification(char c);

#endif