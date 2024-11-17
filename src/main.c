/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:04:14 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/16 14:04:54 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_arg_number(int argc)
{
	if (argc != 2)
		ft_error("\n Invalid arguments number\n");
}

int	main(int argc, char **argv)
{
	t_cube	cube;

	check_arg_number(argc);
	ft_bzero(&cube, sizeof(t_cube));
	check_extension(argv[1], &cube);
	get_len(&cube);
	read_map(&cube);
	check_perimeters(&cube);
	count_thing(&cube);
	// player_initial_position(&cube);
	// verification(&cube);
	// verification_of_playalibtly(&cube);
	// read_map(&cube);
	// cube.mlx = mlx_init();
	// cube.mlx_win = mlx_new_window(cube.mlx, cube.map.x * 100,
	// 		cube.map.y * 100, "Cub3D");
	// hooks(&cube);
	// charg_img(&cube);
	// mlx_loop(cube.mlx);
	return (0);
}
