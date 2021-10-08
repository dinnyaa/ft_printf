/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:01:10 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:02:28 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ui_len(t_form temp, int *size_space, int *size_zero, int size)
{
	int len;

	len = temp.width - (temp.length > size ? temp.length : size);
	if (len > 0)
	{
		if (temp.zero && !temp.length && !temp.dot)
			*size_zero = len;
		else
			*size_space = len;
	}
}

void	print_final_ui(t_form temp, int *size_space, int *size_zero, t_ui num)
{
	if (!temp.minus)
		put_space(*size_space);
	put_zero(*size_zero);
	ft_putnbr_base(num, "0123456789");
	if (temp.minus)
		put_space(*size_space);
}

int		print_unsigned_int(t_ui num, t_form temp)
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
			(temp.length < ulen(num) ? temp.length : ulen(num));
	if (temp.width)
		ui_len(temp, &size_space, &size_zero, ulen(num));
	print_final_ui(temp, &size_space, &size_zero, num);
	return (size_space + size_zero + ulen(num));
}
