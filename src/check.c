/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:40:42 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:44:44 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_form		checks(const char *form, va_list vl)
{
	t_form	temp;
	int		i;

	i = 0;
	temp = initialize_struct_flags(form, &i);
	temp.width = check_width_length(&form[i], vl, &i);
	if (temp.minus || temp.width < 0)
		temp.zero = 0;
	if (temp.width < 0)
	{
		temp.width *= -1;
		temp.minus = 1;
	}
	if (form[i] == '.')
	{
		i++;
		temp.dot = 1;
		temp.length = check_width_length(&form[i], vl, &i);
		if (temp.length < 0)
			temp.dot = 0;
	}
	temp.type = check_type(form[i]);
	return (temp);
}

int			check_zero(char c)
{
	return (c == '0');
}

int			check_minus(char c)
{
	return (c == '-');
}

int			check_width_length(const char *form, va_list vl, int *i)
{
	int width;

	width = 0;
	if (form[0] >= '0' && form[0] <= '9')
		width = ft_atoi(form, i);
	if (form[0] == '*')
	{
		width = va_arg(vl, int);
		(*i)++;
	}
	if (form[0] == ' ' && form[1] == '*')
	{
		width = va_arg(vl, int);
		(*i) += 2;
	}
	return (width);
}

char		check_type(char c)
{
	char	*types;
	int		i;

	i = 0;
	types = "cspdi%uxX";
	while (types[i] != '\0')
	{
		if (c == types[i])
			return (c);
		++i;
	}
	return ('0');
}
