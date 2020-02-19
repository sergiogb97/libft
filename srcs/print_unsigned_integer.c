/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:25:26 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/08 15:26:27 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_zero(uintmax_t nbr, t_struct *f)
{
	return ((!nbr && f->precision && !f->precision_val) ? 1 : 0);
}

static void	print_unsigned_integer_left_align(uintmax_t nbr, t_struct *f)
{
	char	*utoa;
	int		nbrlen;
	int		total_pad;
	int		iszero;

	iszero = (is_zero(nbr, f));
	utoa = (iszero) ? ft_strdup("") : ft_utoa(nbr);
	nbrlen = (iszero) ? 0 : ft_nbrlen(nbr, 10);
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	while (f->precision_val > nbrlen)
	{
		f->len += write(f->fd, "0", 1);
		f->precision_val--;
	}
	f->len += write(f->fd, utoa, nbrlen);
	while (f->width > total_pad)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	free(utoa);
}

static void	print_unsigned_integer_right_align(uintmax_t nbr, t_struct *f)
{
	char	*utoa;
	char	pad;
	int		nbrlen;
	int		total_pad;
	int		iszero;

	iszero = (is_zero(nbr, f));
	utoa = (iszero) ? ft_strdup("") : ft_utoa(nbr);
	pad = (f->zero && !f->precision) ? '0' : ' ';
	nbrlen = (iszero) ? 0 : ft_nbrlen(nbr, 10);
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	while (f->width > total_pad)
	{
		f->len += write(f->fd, &pad, 1);
		f->width--;
	}
	while (f->precision_val > nbrlen)
	{
		f->len += write(f->fd, "0", 1);
		f->precision_val--;
	}
	f->len += write(f->fd, utoa, nbrlen);
	free(utoa);
}

void		print_unsigned_integer(char type, t_struct *f, va_list args)
{
	uintmax_t nbr;

	if (type == 'u')
	{
		nbr = va_arg(args, unsigned int);
		if (f->minus)
			print_unsigned_integer_left_align(nbr, f);
		else
			print_unsigned_integer_right_align(nbr, f);
	}
}
