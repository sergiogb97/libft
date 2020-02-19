/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:06:58 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/13 18:47:12 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*cat;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(cat = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	i = 0;
	while (len1--)
		cat[i++] = *s1++;
	while (len2--)
		cat[i++] = *s2++;
	cat[i] = '\0';
	return (cat);
}
