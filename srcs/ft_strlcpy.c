/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:04:33 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/13 18:44:35 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	j;
	size_t	len;

	if (!src)
		return (0);
	j = ft_strlen(dst);
	len = j + dstsize;
	i = 0;
	while (src[i] && ++j < (len))
	{
		dst[i] = src[i];
		i++;
	}
	if (j < (j + dstsize))
		dst[i] = '\0';
	else if (dstsize > 0)
		dst[--i] = '\0';
	return (ft_strlen(src));
}
