/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:05:38 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/13 17:37:06 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_atoi(const char *str)
{
	unsigned int	atoi;
	int				flag;

	flag = 0;
	while ((8 < *str && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = 1;
		str++;
	}
	atoi = 0;
	while (ft_isdigit(*str))
	{
		atoi = (atoi * 10) + (*str - 48);
		str++;
	}
	if (flag)
		atoi = -atoi;
	return (atoi);
}
