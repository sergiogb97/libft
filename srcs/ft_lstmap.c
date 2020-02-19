/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:26:39 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 19:26:41 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*aux;

	(void)(*del);
	if (!lst || !f)
		return (NULL);
	aux = ft_lstnew(f(lst));
	if (!aux)
		return (NULL);
	map = aux;
	while (lst->next)
	{
		lst = lst->next;
		aux->next = ft_lstnew(f(lst));
		aux = aux->next;
	}
	return (map);
}
