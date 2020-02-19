/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:15:41 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/08 15:21:22 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_struct	*init_flags(void)
{
	t_struct	*f;

	if (!(f = malloc(sizeof(t_struct))))
		return (NULL);
	f->pos = 0;
	f->len = 0;
	f->fd = 1;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->precision = 0;
	f->precision_val = 0;
	f->total_pad = 0;
	return (f);
}

int				ft_printf(const char *string, ...)
{
	int			len;
	va_list		args;
	t_struct	*flags;

	if (!(flags = init_flags()))
		return (-1);
	flags->fd = 1;
	va_start(args, string);
	if (string[0] == '%' && !string[1])
		;
	else if (!(ft_strchr(string, '%')))
		flags->len += write(flags->fd, string, ft_strlen(string));
	else
		process_string(string, flags, args);
	len = flags->len;
	free(flags);
	va_end(args);
	return (len);
}
