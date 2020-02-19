/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:18:57 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/12/12 19:02:16 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	print_string_left_align(char *str, t_struct *f)
{
	int	strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision && strlen > 0 && strlen > f->precision_val)
		strlen = f->precision_val;
	f->len += write(f->fd, str, strlen);
	while (f->width > strlen)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	print_string_right_align(char *str, t_struct *f)
{
	int		strlen;
	char	pad;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->precision && strlen > 0 && strlen > f->precision_val)
		strlen = f->precision_val;
	pad = (f->zero) ? '0' : ' ';
	while (f->width > strlen)
	{
		f->len += write(f->fd, &pad, 1);
		f->width--;
	}
	f->len += write(f->fd, str, strlen);
}

void		print_string(char type, t_struct *f, va_list args)
{
	char	*str;

	if (type == 's')
	{
		str = va_arg(args, char *);
		if (f->minus)
			print_string_left_align(str, f);
		else
			print_string_right_align(str, f);
	}
}
