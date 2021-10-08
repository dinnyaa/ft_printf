/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:57:37 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:58:21 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		num_size(int num)
{
	int size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

int		len(long n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ulen(t_ull n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		hex_len(t_ull num)
{
	int len;

	len = 0;
	if (num == 0)
		len++;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
