/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:53:56 by sgarcia-          #+#    #+#             */
/*   Updated: 2020/01/10 17:53:58 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(uintmax_t nbr, int base)
{
	int	len;

	len = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
