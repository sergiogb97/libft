/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:05:19 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/13 17:59:21 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *p, const char *q, size_t len)
{
	int i;
	int j;
	int flag;

	if (!*q)
		return (&*(char *)p);
	i = 0;
	while (p[i] && len--)
	{
		flag = len + 1;
		j = 0;
		while (p[i + j] && (q[j] == p[i + j]) && flag--)
		{
			if (!q[j + 1])
				return ((char *)&p[i]);
			j++;
		}
		i++;
	}
	return (0);
}
