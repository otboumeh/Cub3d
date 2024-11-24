/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:34:23 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/24 12:05:50 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* The function space_verification checks whether a given character c 
is a type of whitespace character. It returns 1
if c is any of the following characters, and 0 */

int	space_verification(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}
/* Calculate the lenth of the given array*/
int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
/* Printing error msg and exit the program */
void error_exit()
{
	printf("Colors error");
	exit(1);
}
/* Verificate the color string if valid or not */
int is_number(const char *str)
{
    if (!str || *str == '\0')
        return (0);

    while (*str == ' ' || *str == '\t')
        str++;

    if (*str == '\0')
        return (0);
    while (*str >= '0' && *str <= '9')
        str++;
    while (*str == ' ' || *str == '\t')
        str++;
	if (*str != '\n' && *str != '\0')
		return(0);
    return (1); 
}


