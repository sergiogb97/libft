/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:04:53 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/07 19:05:05 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_dst;
	size_t	size_src;
	int		pos;
	int		i;
	int		j;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (dstsize < size_dst)
		return (dstsize + size_src);
	i = 0;
	j = size_dst;
	pos = dstsize - size_dst;
	while (src[i] && pos-- > 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (size_dst + size_src);
}
