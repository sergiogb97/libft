/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:03:29 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/07 19:03:40 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*found;

	if (!c)
		return (ft_strchr(s, c));
	found = 0;
	while ((p = (ft_strchr(s, c))))
	{
		found = p;
		s = p + 1;
	}
	return (found);
}
