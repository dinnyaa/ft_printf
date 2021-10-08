/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:10:14 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:11:32 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_percent(t_form temp)
{
	int size;

	size = (temp.width) ? (temp.width - 1) : 0;
	if (temp.zero && !temp.minus)
		put_zero(size);
	else if (size && !temp.minus)
		put_space(size);
	ft_putchar('%');
	if (!temp.zero && temp.minus)
		put_space(size);
	return (size + 1);
}
