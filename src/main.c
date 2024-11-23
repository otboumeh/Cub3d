/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:04:14 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/23 13:43:52 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_arg_number(int argc)
{
	if (argc != 2)
		ft_error("\n Invalid arguments number\n");
}
int	verification_start(t_cube *cube,\
		t_player_position *player_position, char **argv)
{
	if(read_file(argv[1], cube) == 1)
		return (1);
	
}
int	main(int argc, char **argv)
{
	t_cube	cube;
	t_player_position player_position;
	check_arg_number(argc);
	ft_bzero(&cube, sizeof(t_cube));
	check_extension(argv[1], &cube);
	if(verification_start(&cube, &player_position,argv))
		return(1);
	return (0);
}
