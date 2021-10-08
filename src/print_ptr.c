/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:34:02 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:39:47 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_ptr(void *p, t_form temp)
{
	int		size_space;
	t_ull	ptr;
	int		size_ptr;

	ptr = (t_ull)p;
	size_ptr = hex_len(ptr);
	size_space = (temp.width > size_ptr ? (temp.width - size_ptr - 2) : 0);
	if (!temp.minus)
		put_space(size_space);
	ft_putstr("0x");
	!p ? ft_putchar('0') : ft_putnbr_base(ptr, "0123456789abcdef");
	if (temp.minus)
		put_space(size_space);
	return (size_ptr + size_space + 2);
}
