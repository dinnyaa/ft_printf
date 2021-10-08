/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaghdas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:06:26 by dbaghdas          #+#    #+#             */
/*   Updated: 2021/03/23 17:13:13 by dbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;
typedef unsigned int		t_ui;
typedef long long			t_ll;
typedef struct				s_form
{
	int						zero;
	int						minus;
	int						width;
	int						dot;
	int						length;
	char					type;
}							t_form;

int							ft_printf(const char *format, ...);
t_form						checks(const char *form, va_list vl);
int							check_width_length(const char *form, va_list vl,
		int *i);
int							check_zero(char c);
int							num_size(int num);
char						check_type(char c);
int							check_minus(char c);
int							forward(const char *form, char c);
t_form						initialize_struct_flags(const char *form, int *i);
int							len(long n);
int							ulen(t_ull num);
int							set_arg_type(t_form temp, va_list list);
int							ft_atoi(const char *format, int *i);
int							ft_putchar(char c);
int							ft_putstr(char *str);
void						ft_putnstr(char *str, int size);
int							ft_strlen(const char *s);
long						ft_abs(long n);
void						put_space(int size);
void						put_zero(int size);
int							print_decimal(int num, t_form temp);
void						print_final_dec(t_form temp,
		int *size_space, int *size_zero, int num);
int							print_char(char c, t_form temp);
int							print_str(char *str, t_form temp);
int							print_ptr(void *p, t_form temp);
int							print_hex(t_ui num, t_form temp);
void						print_final_hex(t_form temp,
		int size_zero, int size_space, t_ui num);
int							print_percent(t_form temp);
int							print_unsigned_int(t_ui num, t_form temp);
void						print_final_ui(t_form temp, int *size_space,
		int *size_zero, t_ui num);
void						ft_putnbr_base(t_ull num, char *base);
int							hex_len(t_ull num);
void						dec_len(t_form temp,
		int *size_space, int *size_zero, int num);
void						ui_len(t_form temp,
		int *size_space, int *size_zero, int size);

#endif
