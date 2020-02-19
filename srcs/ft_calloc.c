/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:05:56 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/13 17:36:32 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		mem;
	void	*m;

	mem = count * size;
	if (!(m = malloc(mem)))
		return (NULL);
	return (ft_memset(m, 0, mem));
}
