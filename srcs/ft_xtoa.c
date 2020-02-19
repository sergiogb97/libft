/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:38:54 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/10 12:54:38 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_xtoa(uintmax_t nbr)
{
	char		*xtoa;
	char		*base;
	int			len;
	uintmax_t	nb;

	base = "0123456789abcdef";
	len = 1;
	nb = nbr;
	while (nb /= 16)
		len++;
	if (!(xtoa = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	xtoa[len] = '\0';
	nb = nbr;
	while (len--)
	{
		xtoa[len] = base[nb % 16];
		nb /= 16;
	}
	return (xtoa);
}
