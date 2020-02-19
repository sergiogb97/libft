/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:31:27 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 17:57:03 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_w(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static int	cpy_w(char *dst, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		*dst++ = *s++;
		i++;
	}
	*dst = '\0';
	return (i);
}

static int	len_w(const char *s, char c)
{
	int len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char		**ft_split(const char *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	if (!(split = malloc(sizeof(char *) * (count_w(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(split[i] = malloc(sizeof(char) * (len_w(s, c) + 1))))
			return (NULL);
		if (*s)
			s += cpy_w(split[i++], s, c);
	}
	split[i] = NULL;
	return (split);
}
