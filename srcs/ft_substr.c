/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:06:42 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 18:35:07 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	if (!(sub = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (*s && (len - i))
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
