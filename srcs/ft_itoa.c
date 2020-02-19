/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:41:44 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/18 18:53:32 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	int		nb;

	len = ((n <= 0) ? 1 : 0);
	nb = n;
	while (++len && nb)
		nb /= 10;
	if (!(itoa = malloc(sizeof(char) * len)))
		return (NULL);
	itoa[--len] = '\0';
	*itoa = '0';
	nb = n;
	while (nb)
	{
		itoa[--len] = '0' + ((n < 0) ? -1 : 1) * (nb % 10);
		nb /= 10;
	}
	if (n < 0)
		*itoa = '-';
	return (itoa);
}
