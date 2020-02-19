/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:56:37 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/11 16:56:27 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *c)
{
	int		i;
	int		len;
	char	swap;

	len = ft_strlen(c) - 1;
	i = 0;
	while (i < len)
	{
		swap = c[i];
		c[i] = c[len];
		c[len] = swap;
		i++;
		len--;
	}
	return (c);
}
