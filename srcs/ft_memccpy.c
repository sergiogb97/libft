/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:58:27 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/11 21:20:08 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

	c = (unsigned char)c;
	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	while (n--)
	{
		*cpy_dst++ = *cpy_src;
		if (c == *cpy_src++)
			return (cpy_dst);
	}
	return (NULL);
}
