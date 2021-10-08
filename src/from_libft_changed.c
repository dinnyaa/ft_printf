/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_changed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:52:16 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:54:59 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnstr(char *str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putchar(str[i]);
}

void	ft_putnbr_base(t_ull num, char *base)
{
	t_ull		size;

	size = 0;
	while (base[size] != '\0')
		size++;
	if (num < 0)
	{
		num = num * (-1);
		ft_putchar('-');
	}
	if (num >= size)
	{
		ft_putnbr_base(num / size, base);
		ft_putnbr_base(num % size, base);
	}
	else
		ft_putchar(base[num]);
}

long	ft_abs(long n)
{
	return ((n > 0) ? n : -n);
}
