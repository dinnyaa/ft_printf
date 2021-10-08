/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:55:05 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:57:24 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		forward(const char *form, char c)
{
	int i;

	i = 0;
	if (c != '0')
	{
		while (form[i] != check_type(c))
			i++;
	}
	return (i + 1);
}

void	put_space(int size)
{
	int	i;

	i = 0;
	while (i++ < size)
		ft_putchar(' ');
}

void	put_zero(int size)
{
	int	i;

	i = 0;
	while (i++ < size)
		ft_putchar('0');
}
