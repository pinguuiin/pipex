/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:23:08 by piyu              #+#    #+#             */
/*   Updated: 2024/11/15 20:54:09 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	if (*lst)
	{
		ptr = *lst;
		while (ptr)
		{
			temp = ptr -> next;
			ft_lstdelone(ptr, del);
			ptr = temp;
		}
	}
	*lst = NULL;
}
