/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:02:54 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:04:40 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_form		temp;
	int			bytes;
	int			i;
	const char	*form;

	i = 0;
	bytes = 0;
	va_start(list, format);
	while (format[i])
	{
		if (format[i++] == '%')
		{
			form = format + i;
			temp = checks(form, list);
			i += forward(form, temp.type);
			bytes += set_arg_type(temp, list);
		}
		else
			bytes += ft_putchar(format[i - 1]);
	}
	va_end(list);
	return (bytes);
}
