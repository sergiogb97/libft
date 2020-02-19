/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:11:32 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/08 15:27:27 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	reset_flags(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_val = 0;
	f->total_pad = 0;
}

static void	print_value(const char *str, t_struct *f, va_list args)
{
	char type;

	type = str[f->pos];
	if (type == 'c' || type == '%')
		print_char(type, f, args);
	else if (type == 's')
		print_string(type, f, args);
	else if (type == 'p')
		print_pointer(type, f, args);
	else if (type == 'd' || type == 'i')
		print_integer(type, f, args);
	else if (type == 'u')
		print_unsigned_integer(type, f, args);
	else if (type == 'x' || type == 'X')
		print_hexadecimal(type, f, args);
}

void		process_string(const char *str, t_struct *f, va_list args)
{
	while (str[f->pos])
	{
		if (str[f->pos] == '%')
		{
			f->pos++;
			if (ft_strchr("0123456789-.*", str[f->pos]))
				parse_modifiers(str, f, args);
			if (ft_strchr("cspdiuxX%", str[f->pos]))
			{
				print_value(str, f, args);
				reset_flags(f);
			}
			if (!str[f->pos])
				break ;
		}
		else
			f->len += write(1, &str[f->pos], 1);
		f->pos++;
	}
}
