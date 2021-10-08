/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 16:27:00 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 16:30:58 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_form		initialize_struct_flags(const char *form, int *i)
{
	t_form t;
 
	t.zero = 0;
	t.minus = 0;
	t.width = 0;
	t.dot = 0;
	t.length = 0;
	t.type = '0';
	if ((t.minus = check_minus(form[*i])) == 1)
		(*i)++;
	if ((t.zero = check_zero(form[*i])) == 1)
		(*i)++;
	if ((form[*i]) == '-')
	{
		t.minus = 1;
		t.zero = 0;
		(*i)++;
	}
	return (t);
}


