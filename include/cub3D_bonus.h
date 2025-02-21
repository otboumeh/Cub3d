/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:31:01 by dangonz3          #+#    #+#             */
/*   Updated: 2025/02/21 13:56:03 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include <stdint.h>

# define WIN_WIDTH 2000
# define WIN_HEIGHT 1000
# define PLAYER_SIZE 10
# define PI 3.14159265
# define ANGLE_ROTATION_SIZE 5
# define FRAMES 30 
# define TILE_SIZE 1000
# define NUM_RAYS WIN_WIDTH

# define FALSE 0
# define TRUE 1

# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF

# define OPEN_TIME 60
# define OPEN_DISTANCE TILE_SIZE * 2
# define DOOR_ROUTE "./texture/doom_door.png"

# define SPRITE_ROUTE "./texture/cocodemon.png"
# define WHITE_DECIMAL 4294967295

typedef struct s_player_position
{
	int				x;
	int				y;
	int				pos_x;
	int				pos_y;
	char			orientation;
}					t_player_position;

typedef struct s_cube
{
	char			**map;
	int				player_x;
	int				player_y;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				floor_color[3];
	int				ceiling_color[3];
	int				max_y_size;
	int				max_x_size;
	char			*raw_map;
}					t_cube;

typedef struct s_door
{
	int				x_door;
	int				y_door;
	int				is_closed;
	int				opening;
	int				closing;
}	t_door;

typedef struct s_texture
{
	int				width;
	int				height;
	unsigned int	**pixels;
}	t_texture;

typedef struct s_ray
{
	float			rayangle;
	int				ray_index;

	int				isRayFacingDown;
	int				isRayFacingUp;
	int				isRayFacingLeft;
	int				isRayFacingRight;

	float			xintercept;
	float			yintercept;

	float			xstep;
	float			ystep;

	float			next_horz_touch_x;
	float			next_horz_touch_y;
	float			next_vertical_touch_x;
	float			next_vertical_touch_y;
	float			x_to_check;
	float			y_to_check;

	float			horizontal_wall_hit_x;
	float			horizontal_wall_hit_y;
	char			horizontal_wall_content;
	int				found_horizontal_wall_hit;
	float			vertical_wall_hit_x;
	float			vertical_wall_hit_y;
	char			vertical_wall_content;
	int				found_vertical_wall_hit;

	float			horizontal_hit_distance;
	float			vertical_hit_distance;

	float			distance;
	float			wall_hit_x;
	float			wall_hit_y;
	float			was_hit_vertical;

	float			perp_distance;
	float			distance_proj_plane;
	float			wall_strip_height;
	int				wall_top_pixel;
	int				wall_bottom_pixel;
	unsigned int	wall_color;

	int				is_sprite;
	float			horizontal_sprite_hit_x;
	float			horizontal_sprite_hit_y;
	float			vertical_sprite_hit_x;
	float			vertical_sprite_hit_y;
	float			sprite_horizontal_hit_distance;
	float			sprite_vertical_hit_distance;
	float			sprite_hit_x;
	float			sprite_hit_y;
	float			sprite_distance;
	int				sprite_was_hit_vertical;

	float			sprite_perp_distance;
	float			sprite_distance_proj_plane;
	float			sprite_strip_height;
	int				sprite_top_pixel;
	int				sprite_bottom_pixel;

	int				im_door;
	int				door_number;
} t_ray;

typedef struct s_cub
{
	void			*mlx;
	mlx_image_t		*win_mlx3D;

	t_cube			*parse_struct;

	char			**map;
	int				player_direction;
	int				map_max_y;
	int				map_max_x;

	unsigned int	ceiling;
	unsigned int	floor;
	t_texture		*wall_n;
	t_texture		*wall_s;
	t_texture		*wall_w;
	t_texture		*wall_e;
	t_texture		*door_t;

	t_texture		*sprite_t;

	float			p_fov;
	float			p_turnspeed;
	float			p_walkspeed;
	float			p_turnspeed_original;

	float			p_rotationangle;
	float			p_y;
	float			p_x;

	int				p_walkdirection;
	int				p_strafedirection;
	int				p_turndirection;

	t_ray			*rays;

	unsigned int	strip[WIN_HEIGHT];

	unsigned int	timelastframe;

	float			minimap_start_y;
	float			minimap_start_x;
	float			minimap_area_y;
	float			minimap_area_x;
	float			minimap_tile_size;
	float			minimap_player_size;

	unsigned int	sprite_strip[WIN_HEIGHT];

	t_door			*doors;
	int				door_number;
	int				door_closing;
}					t_cub;

void		init_doors(t_cub *c);
void		locate_doors(t_cub *c);
void		open_doors(t_cub *c);
void		detect_doors(t_cub *c, t_ray *r);
void		update_doors(t_cub *c);

void		c_error(char *str, t_cub *c);
void		c_close(t_cub *c);
void		free_memory(t_cub *c);
void		free_t_texture(t_texture *t);

int			init_game(t_cub *c);
int			load_texture(t_cub *c, t_texture **strc, char *route);
int			load_texture_aux(t_cub *c, t_texture *texture, mlx_texture_t *png);
void		get_map_max_x(t_cub *c);

void		init_player(t_cub *c);
int			locate_player(t_cub *c);
void		set_player_position(int y, int x, t_cub *c);

void		game_loop(void *param);

void		minimap_render(t_cub *c);
void		minimap_print(int x_map, int y_map, uint32_t element, t_cub *c);
void		minimap_print_player(t_cub *c);
void		init_minimap(t_cub *c);

void		check_extension(char *argv1);
int			read_file(char *file, t_cube *cube);

void		free_line(char *line, t_cube *cube);
void		free_content(t_cube *cube);
void		array_free(char **array);

int			validate_map(t_cube *cube, t_player_position *player_position);

void		check_arg_number(int argc);
int			verification_start(t_cube *cube, \
			t_player_position *player_position, char **argv);
int			parser(int argc, char **argv);
void		reach_last_character(const char *file_path);

int			parse_line(char *line, t_cube *cube);
char		*line_verification(char *line);
int			parse_colors(char *line, int color[3]);
void		parse_map(char *line, t_cube *cube);

void		delete_tab(char ***map, int i);
int			last_verification(t_cube *cube, t_player_position *player_position);
int			validate_file(t_cube *cube);

int			space_verification(char c);
int			array_len(char **array);
void		error_exit(void);
int			is_number(const char *str);
void		set_initial_position(t_player_position *player_position, int x, \
				int y, char orientation);

void		process_player_input(void *param);
void		mouse_hook(t_cub *c);
void		update_player_position(t_cub *c);
int			check_wall_collision(t_cub *c, float x, float y);

void		find_horizontal_hit(t_cub *c, t_ray *r, float rayAngle);
void		find_horizontal_hit_loop(t_cub *c, t_ray *r);
void		find_vertical_hit(t_cub *c, t_ray *r, float rayAngle);
void		find_vertical_hit_loop(t_cub *c, t_ray *r);
int			has_wall_at(t_cub *c, float x, float y);

void		ray_caster(t_cub *c);
void		cast_ray(t_cub *c, t_ray *r, int ray_index, float rayAngle);
void		init_ray_struct(t_ray *r, int ray_index, float rayAngle);
void		select_ray_hit(t_cub *c, t_ray *r);

void		ray_render(t_cub *c);
int			init_data_render(t_cub *c, t_ray *r);
void		render(t_cub *c, t_ray *r);
void		calculate_wall_strip(t_cub *c, t_ray *r, t_texture *text, int x);
void		draw_wall_strip(t_cub *c, int x);

void		choose_sprite_hit(t_cub *c, t_ray *r);
void		sprite_render(t_cub *c);
void		sprite_render_aux(t_cub *c, t_ray *r);
void		calculate_sprite_strip(t_cub *c, t_ray *r, t_texture *t, int x);
void		draw_sprite_strip(t_cub *c, t_ray *r, int x);

float		normalize_angle(float angle);
uint32_t	get_color(uint8_t *ptr);
uint32_t	get_color_alt(int *ptr);
float		distance_between_points(float x1, float y1, float x2, float y2);

#endif