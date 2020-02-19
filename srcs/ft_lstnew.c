/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgarcia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:26:55 by sgarcia-          #+#    #+#             */
/*   Updated: 2019/11/19 19:26:58 by sgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(const void *content)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->content = (void *)content;
	lst->next = NULL;
	return (lst);
}
