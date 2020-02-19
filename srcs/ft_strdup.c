/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:06:25 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/11 21:13:48 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	if (!(cpy = malloc(sizeof(char) * len)))
		return (NULL);
	len = ft_strlcpy(cpy, s1, len);
	return (cpy);
}
