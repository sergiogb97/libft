/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:59:18 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/08 17:18:18 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	p = (unsigned char *)s;
	c = (unsigned char)c;
	while (n--)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (0);
}
