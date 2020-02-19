/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:07:24 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/12/12 19:07:30 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	print_char_left_align(unsigned char c, t_struct *f)
{
	f->len += write(f->fd, &c, 1);
	while (f->width > 1)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
}

static void	print_char_right_align(unsigned char c, t_struct *f)
{
	char	pad;

	pad = (f->zero) ? '0' : ' ';
	while (f->width > 1)
	{
		f->len += write(f->fd, &pad, 1);
		f->width--;
	}
	f->len += write(f->fd, &c, 1);
}

void		print_char(char type, t_struct *f, va_list args)
{
	char	c;

	if (type == 'c')
		c = (char)va_arg(args, int);
	else if (type == '%')
		c = type;
	if (type == 'c' || type == '%')
	{
		if (f->minus)
			print_char_left_align(c, f);
		else
			print_char_right_align(c, f);
	}
}
