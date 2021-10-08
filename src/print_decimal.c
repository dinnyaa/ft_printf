/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:51:49 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:58:04 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dec_len(t_form temp, int *size_space, int *size_zero, int num)
{
	int len;

	len = temp.width -
		(temp.length > num_size(num) ? temp.length : num_size(num));
	if (len > 0)
	{
		if (temp.zero && !temp.length && !temp.dot)
			*size_zero = len - ((num < 0) ? 1 : 0);
		else
			*size_space = len - ((num < 0) ? 1 : 0);
	}
}

void	print_final_dec(t_form temp, int *size_space, int *size_zero, int num)
{
	if (!temp.minus)
		put_space(*size_space);
	if (num < 0)
		ft_putchar('-');
	put_zero(*size_zero);
	ft_putnbr_base(ft_abs(num), "0123456789");
	if (temp.minus)
		put_space(*size_space);
}

int		print_decimal(int num, t_form temp)
{
	int size_space;
	int size_zero;

	size_space = 0;
	size_zero = 0;
	if (temp.dot && !temp.length && !num)
	{
		put_space(temp.width);
		return (temp.width);
	}
	if (temp.length)
		size_zero = temp.length -
			(temp.length < num_size(num) ? temp.length : num_size(num));
	if (temp.width)
		dec_len(temp, &size_space, &size_zero, num);
	print_final_dec(temp, &size_space, &size_zero, num);
	return (size_space + size_zero + len(num));
}
