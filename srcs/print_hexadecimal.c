/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:36:46 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/08 19:38:20 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_zero(uintmax_t nbr, t_struct *f)
{
	return ((!nbr && f->precision && !f->precision_val) ? 1 : 0);
}

static void	hex_upper(char *hex)
{
	int i;

	i = 0;
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		i++;
	}
}

static void	print_hexadecimal_left_align(uintmax_t nbr, t_struct *f, char type)
{
	char	*hex;
	int		nbrlen;
	int		total_pad;
	int		iszero;

	iszero = (is_zero(nbr, f));
	hex = (iszero) ? ft_strdup("") : ft_xtoa(nbr);
	nbrlen = (iszero) ? 0 : ft_nbrlen(nbr, 16);
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	if (type == 'X')
		hex_upper(hex);
	while (f->precision_val > nbrlen)
	{
		f->len += write(f->fd, "0", 1);
		f->precision_val--;
	}
	f->len += write(f->fd, hex, nbrlen);
	while (f->width > total_pad)
	{
		f->len += write(f->fd, " ", 1);
		f->width--;
	}
	free(hex);
}

static void	print_hexadecimal_right_align(uintmax_t nbr, t_struct *f, char type)
{
	char	*hex;
	char	pad;
	int		nbrlen;
	int		total_pad;
	int		iszero;

	iszero = (is_zero(nbr, f));
	hex = (iszero) ? ft_strdup("") : ft_xtoa(nbr);
	pad = (f->zero && !f->precision) ? '0' : ' ';
	nbrlen = (iszero) ? 0 : ft_nbrlen(nbr, 16);
	total_pad = (nbrlen > f->precision_val) ? nbrlen : f->precision_val;
	if (type == 'X')
		hex_upper(hex);
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
	f->len += write(f->fd, hex, nbrlen);
	free(hex);
}

void		print_hexadecimal(char type, t_struct *f, va_list args)
{
	uintmax_t nbr;

	if (type == 'x' || type == 'X')
	{
		nbr = va_arg(args, unsigned int);
		if (f->minus)
			print_hexadecimal_left_align(nbr, f, type);
		else
			print_hexadecimal_right_align(nbr, f, type);
	}
}
