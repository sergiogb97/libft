/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:22:26 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/20 15:42:35 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
	else
		*alst = new;
}
