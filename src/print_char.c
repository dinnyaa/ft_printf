/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:55:58 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 15:57:44 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_char(char c, t_form temp)
{
	int		size_space;

	size_space = (temp.width) ? (temp.width - 1) : 0;
	if (!temp.minus)
		put_space(size_space);
	ft_putchar(c);
	if (temp.minus)
		put_space(size_space);
	return (1 + size_space);
}
