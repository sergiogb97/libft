/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:26:24 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 18:25:42 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(&s1[start]);
	if (len)
	{
		while (s1[start + len - 1] && ft_strchr(set, s1[start + len - 1]))
			len--;
	}
	if (!(trim = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(trim, &s1[start], len + 1);
	trim[len] = '\0';
	return (trim);
}
