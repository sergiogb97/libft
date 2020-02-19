/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:25:28 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/20 15:55:26 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst && del)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = (*lst)->next;
		}
		*lst = NULL;
	}
}
