/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:03:07 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/07 19:03:19 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *p;

	c = (char)c;
	p = (char *)s;
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (!c)
		return (p);
	return (0);
}
