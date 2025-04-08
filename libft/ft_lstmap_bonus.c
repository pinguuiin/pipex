/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:14:24 by piyu              #+#    #+#             */
/*   Updated: 2024/11/18 04:23:58 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map_n_add(t_list *lst, t_list *new_lst, \
	void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_node;

	new_content = f(lst -> content);
	new_node = ft_lstnew(new_content);
	if (new_node == NULL)
	{
		del(new_content);
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	ft_lstadd_back(&new_lst, new_node);
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	while (lst && f && del)
	{
		new_lst = map_n_add(lst, new_lst, f, del);
		lst = lst -> next;
	}
	return (new_lst);
}
