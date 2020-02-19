/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:22:13 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/10 12:54:16 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_utoa(uintmax_t nbr)
{
	char		*utoa;
	int			len;
	uintmax_t	nb;

	if (nbr == 0)
		return (ft_strdup("0"));
	len = 0;
	nb = nbr;
	while (++len && nb)
		nb /= 10;
	if (!(utoa = malloc(sizeof(char) * len)))
		return (NULL);
	utoa[--len] = '\0';
	nb = nbr;
	while (nb)
	{
		utoa[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (utoa);
}
