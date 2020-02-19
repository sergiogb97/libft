/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:04:33 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/10 17:54:29 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	check_flags(const char *str, t_struct *f)
{
	while (ft_strchr("-0", str[f->pos]))
	{
		if (str[f->pos] == '-')
			f->minus = 1;
		else if (str[f->pos] == '0')
			f->zero = 1;
		f->pos++;
	}
}

static void	set_width(const char *str, t_struct *f, va_list args)
{
	if (str[f->pos] == '*')
	{
		f->width = va_arg(args, int);
		f->minus = (f->width < 0) ? 1 : f->minus;
		f->width = (f->width < 0) ? -f->width : f->width;
		while (str[f->pos] == '*')
			f->pos++;
	}
	if (ft_isdigit(str[f->pos]))
	{
		f->width = ft_atoi(&str[f->pos]);
		while (ft_isdigit(str[f->pos]))
		{
			f->pos++;
			if (str[f->pos] == '*')
				set_width(str, f, args);
		}
	}
}

static void	set_precision(const char *str, t_struct *f, va_list args)
{
	int	precision;

	if (str[f->pos] == '.')
	{
		f->pos++;
		f->precision = 1;
		if (ft_isdigit(str[f->pos]))
		{
			f->precision_val = ft_atoi(&str[f->pos]);
			while (ft_isdigit(str[f->pos]))
				f->pos++;
		}
		else if (str[f->pos] == '*')
		{
			precision = va_arg(args, int);
			if (precision < 0)
				f->precision = 0;
			else
				f->precision_val = precision;
			while (str[f->pos] == '*')
				f->pos++;
		}
	}
}

void		parse_modifiers(const char *str, t_struct *f, va_list args)
{
	check_flags(str, f);
	set_width(str, f, args);
	set_precision(str, f, args);
}
