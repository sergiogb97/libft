/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:54:58 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/10 12:56:31 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	print_pointer_left_align(uintmax_t nbr, t_struct *f)
{
	char	*pt;
	int		nbrlen;
	int		total_pad;

	pt = ft_xtoa(nbr);
	nbrlen = ft_nbrlen(nbr, 16) + 2;
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val + 2;
	f->len += write(f->fd, "0x", 2);
	if (!nbr && f->precision && !f->precision_val)
		return ;
	while (f->precision_val > (nbrlen - 2))
	{
		f->len += write(f->fd, "0", 1);
		f->precision_val--;
	}
	f->len += write(f->fd, pt, nbrlen - 2);
	while (f->width > total_pad)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	free(pt);
}

static void	print_pointer_right_align(uintmax_t nbr, t_struct *f)
{
	char	*pt;
	char	pad;
	int		nbrlen;
	int		total_pad;

	pt = ft_xtoa(nbr);
	pad = (f->zero) ? '0' : ' ';
	nbrlen = ft_nbrlen(nbr, 16) + 2;
	if (!nbr && f->precision && !f->precision_val)
		nbrlen = 0;
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val + 2;
	if (f->zero)
		f->len += write(f->fd, "0x", 2);
	while (f->width-- > total_pad)
		f->len += write(f->fd, &pad, 1);
	if (!f->zero)
		f->len += write(f->fd, "0x", 2);
	if (!nbr && f->precision && !f->precision_val)
		return ;
	while (f->precision_val-- > (nbrlen - 2))
		f->len += write(f->fd, "0", 1);
	f->len += write(f->fd, pt, nbrlen - 2);
	free(pt);
}

void		print_pointer(char type, t_struct *f, va_list args)
{
	uintmax_t	nbr;

	if (type == 'p')
	{
		nbr = (long long)va_arg(args, void *);
		if (f->minus)
			print_pointer_left_align(nbr, f);
		else
			print_pointer_right_align(nbr, f);
	}
}
