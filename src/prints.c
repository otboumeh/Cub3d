/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otboumeh <otboumeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:32:53 by otboumeh          #+#    #+#             */
/*   Updated: 2024/11/24 14:36:40 by otboumeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_puthexa_str(size_t n)
{
	char	buffer[17];
	int		i;
	char	*res;

	ft_memset(buffer, '\0', sizeof(buffer));
	i = 15;
	while (n > 0)
	{
		buffer[i] = HEXU[n % 16];
		n /= 16;
		i--;
	}
	res = strdup(&buffer[i + 1]);
	return (res);
}

static char	*ft_putaddress_str(unsigned long p)
{
	char	*res;
	char	buffer[19];
	int		i;

	ft_memset(buffer, '\0', sizeof(buffer));
	i = 17;
	buffer[0] = '0';
	buffer[1] = 'x';
	while (p > 0)
	{
		buffer[i] = HEXU[p % 16];
		p /= 16;
		i--;
	}
	res = strdup(&buffer[i + 1]);
	return (res);
}

static char	*str_or_null(const char *str)
{
	char	*out;

	if (!str)
		out = ft_strdup("(null)");
	else
		out = ft_strdup(str);
	return (out);
}
static char	*printer(char const *container, va_list *args)
{
	char	*res;

	if (ft_strchr("di", *container))
		res = ft_itoa(va_arg(*args, int));
	if (ft_strchr("xX", *container))
		res = ft_puthexa_str(va_arg(*args, size_t));
	if (*container == 'p')
		res = ft_putaddress_str(va_arg(*args, unsigned long));
	if (*container == 's')
		res = str_or_null(va_arg(*args, char *));
	if (*container == 'c')
	{
		res = malloc(2);
		res[0] = (char)va_arg(*args, int);
		res[1] = '\0';
	}
	if (*container == '%')
		res = strdup("%");
	return (res);
}

static char	*allocate_and_copy(char *old_result, char *tmp, int old_len)
{
	char	*result;

	result = malloc(old_len + ft_strlen(tmp) + 1);
	ft_memcpy(result, old_result, old_len);
	ft_memcpy(result + old_len, tmp, ft_strlen(tmp));
	result[old_len + ft_strlen(tmp)] = '\0';
	free(old_result);
	free(tmp);
	return (result);
}

static char	*handle_percent_case(char const **container, va_list *args,
		char *result)
{
	char	*tmp;
	int		old_len;

	tmp = printer(++(*container), args);
	old_len = ft_strlen(result);
	result = allocate_and_copy(result, tmp, old_len);
	return (result);
}

static char	*handle_normal_case(char const **container, char *result)
{
	char	*tmp;
	int		old_len;

	tmp = malloc(2);
	tmp[0] = **container;
	tmp[1] = '\0';
	old_len = ft_strlen(result);
	result = allocate_and_copy(result, tmp, old_len);
	return (result);
}

char	*ft_sprintf(char const *container, ...)
{
	va_list	args;
	char	*result;

	va_start(args, container);
	result = malloc(sizeof(char));
	*result = '\0';
	while (*container)
	{
		if (*container == '%')
			result = handle_percent_case(&container, &args, result);
		else
			result = handle_normal_case(&container, result);
		container++;
	}
	va_end(args);
	return (result);
}
