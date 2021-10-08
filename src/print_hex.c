/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:04:25 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:08:34 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_final_hex(t_form temp, int size_zero, int size_space, t_ui num)
{
	char *base;

	if (temp.type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!temp.minus)
		put_space(size_space);
	put_zero(size_zero);
	ft_putnbr_base(num, base);
	if (temp.minus)
		put_space(size_space);
}

int		print_hex(t_ui num, t_form temp)
{
	int size_space;
	int size_zero;
	int num_size;

	size_space = 0;
	size_zero = 0;
	num_size = hex_len(num);
	if (temp.dot && !temp.length && !num)
	{
		put_space(temp.width);
		return (temp.width);
	}
	if (temp.length)
		size_zero = temp.length -
			(temp.length < num_size ? temp.length : num_size);
	if (temp.width)
		ui_len(temp, &size_space, &size_zero, num_size);
	print_final_hex(temp, size_zero, size_space, num);
	return (size_space + size_zero + num_size);
}
