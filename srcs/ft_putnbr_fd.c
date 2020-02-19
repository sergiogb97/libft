/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:44:54 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/18 19:02:09 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)(n);
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((nb % 10 + 48), fd);
}
