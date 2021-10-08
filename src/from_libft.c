/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:51:05 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:52:03 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *format, int *i)
{
	long		result;
	const char	*str;

	result = 0;
	str = format;
	while (*str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + ((*str) - '0');
		str++;
		(*i)++;
	}
	return (result);
}

int		ft_putstr(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		write(1, str, 1);
		++len;
		str++;
	}
	return (len);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}
