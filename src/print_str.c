/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:58:14 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:01:02 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_str(char *str, t_form temp)
{
	int size_space;
	int size_str;

	if (!str)
		str = "(null)";
	size_str = ft_strlen(str);
	if (temp.dot)
		size_str = (temp.length < size_str ? temp.length : size_str);
	size_space = (temp.width - size_str > 0) ? temp.width - size_str : 0;
	if (!temp.minus)
		put_space(size_space);
	ft_putnstr(str, size_str);
	if (temp.minus)
		put_space(size_space);
	return (size_str + size_space);
}
