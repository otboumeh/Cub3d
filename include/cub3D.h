/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:31:01 by dangonz3          #+#    #+#             */
/*   Updated: 2024/11/30 12:27:37 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <math.h>

# define IMG_WIDHT 64
# define IMG_HEIGHT 64

// ---------------------- MLX ----------------------

typedef struct s_cub
{
	mlx_t			*mlx;

	int				map_axis_y;
	int				map_axis_x;
	char			**map;
	int				map_bool;

	int				p_y;
	int				p_x;

	char			*png_floor;
	mlx_texture_t	*texture_floor;
	mlx_image_t		*img_floor;
	
	char			*png_wall;
	mlx_texture_t	*texture_wall;	
	mlx_image_t		*img_wall;

	char			*png_player;
	mlx_texture_t	*texture_player;	
	mlx_image_t		*img_player;

} t_cub;

// ---------------------- PARSER ----------------------

typedef struct s_player_position
{
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;
	char	orientation;

}			t_player_position;

typedef struct s_cube
{
    char        **map;               // The parsed map
    int         player_x;            // Player's X position
    int         player_y;            // Player's Y position
    char        *north_texture;      // North texture path
    char        *south_texture;      // South texture path
    char        *west_texture;       // West texture path
    char        *east_texture;       // East texture path
    int         floor_color[3];      // Floor color (RGB)
    int         ceiling_color[3];    // Ceiling color (RGB)
    int         max_y;               // Max Y size of the map
    int         max_x;               // Max X size of the map
    char        *raw_map;            // Temporary raw map
} t_cube;

// ---------------------- MLX ----------------------

//errors
void	free_memory(t_cub *c);
void	free_img(t_cub *c);

//free_memory
void	c_error(char *str, t_cub *c);
void	c_error_img(char *str, t_cub *c);

//image_load
void	image_load(t_cub *c);

//initiate_mlx
void	initiate_mlx(t_cub *c);
void	map_axis_x(t_cub *c);

//loops
void	loops(t_cub *c);
void	key_hooks(void *c_void);

//map_read
void	map_read(char **argv, t_cub *c);
char	*sl_strjoin(char *s1, const char *s2);

//map_render
void	map_render(t_cub *c);
void	map_identify(int i, int x, t_cub *c);

//player_move
void	player_move(t_cub *c);
void 	move(t_cub *c, int n);

// ---------------------- PARSER ----------------------

//parsing.c
int		parse_line(char *line, t_cube *cube);
char	*line_verification(char *line);
int		parse_colors(char *line, int color[3]);
void	parse_map(char *line, t_cube *cube);

//check_map.c
void	check_extension(char *argv1, t_cube *cube);
int		read_file(char *file, t_cube *cube);

//freedom.c
void	free_line(char *line, t_cube *cube);
void	free_content(t_cube *cube);
void	array_free(char **array);

//parser.c
void	check_arg_number(int argc);
int		verification_start(t_cube *cube,\
			t_player_position *player_position, char **argv);
int		parser(int argc, char **argv);
void 	reach_last_character(const char *file_path);
//util_map.c
void	delete_tab(char ***map, int i);
int		last_verification(t_cube *cube, t_player_position *player_position);
int		validate_file(t_cube *cube);

//utils.c
int		space_verification(char c);
int		array_len(char **array);
void 	error_exit();
int		is_number(const char *str);
void	set_initial_position(t_player_position *player_position, int x, int y,
		char orientation);
//print
char	*ft_sprintf(char const *container, ...);

//map_parsing
int	validate_map(t_cube *cube, t_player_position *player_position);

#endif
