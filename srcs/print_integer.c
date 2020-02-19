/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:24:30 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/08 15:24:55 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_zero(int nbr, t_struct *f)
{
	return ((!nbr && f->precision && !f->precision_val) ? 1 : 0);
}

static void	print_integer_left_align(int nbr, t_struct *f)
{
	char	*itoa;
	int		nbrlen;

	itoa = (is_zero(nbr, f)) ? ft_strdup("") : ft_itoa(nbr);
	nbrlen = (is_zero(nbr, f)) ? 0 : ft_strlen(itoa);
	f->total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	if (nbr < 0 && f->precision && nbrlen > f->precision_val)
		f->total_pad--;
	if (nbr < 0 && f->precision)
	{
		f->len += write(f->fd, "-", 1);
		nbrlen--;
		f->total_pad++;
	}
	while (f->precision_val-- > nbrlen)
		f->len += write(f->fd, "0", 1);
	if (nbr < 0 && f->precision)
		f->len += write(f->fd, &itoa[1], nbrlen);
	else
		f->len += write(f->fd, itoa, nbrlen);
	while (f->width-- > f->total_pad)
		f->len += write(f->fd, " ", 1);
	free(itoa);
}

static void	print_integer_right_align(int nbr, t_struct *f)
{
	char	*itoa;
	char	pad;
	int		nbrlen;

	itoa = (is_zero(nbr, f)) ? ft_strdup("") : ft_itoa(nbr);
	nbrlen = (is_zero(nbr, f)) ? 0 : ft_strlen(itoa);
	f->total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	if (nbr < 0 && f->precision && nbrlen < f->precision_val)
		f->total_pad++;
	if (nbr < 0 && (f->zero || f->precision))
		nbrlen--;
	if (nbr < 0 && f->zero && !f->precision)
		f->len += write(f->fd, "-", 1);
	pad = (f->zero && !f->precision) ? '0' : ' ';
	while (f->width-- > f->total_pad)
		f->len += write(f->fd, &pad, 1);
	if (nbr < 0 && f->precision)
		f->len += write(f->fd, "-", 1);
	while (f->precision_val-- > nbrlen)
		f->len += write(f->fd, "0", 1);
	if (nbr < 0 && (f->zero || f->precision))
		f->len += write(f->fd, &itoa[1], nbrlen);
	else
		f->len += write(f->fd, itoa, nbrlen);
	free(itoa);
}

void		print_integer(char type, t_struct *f, va_list args)
{
	int nbr;

	if (type == 'd' || type == 'i')
	{
		nbr = va_arg(args, int);
		if (f->minus)
			print_integer_left_align(nbr, f);
		else
			print_integer_right_align(nbr, f);
	}
}
