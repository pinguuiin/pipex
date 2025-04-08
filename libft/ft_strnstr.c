/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 02:24:37 by piyu              #+#    #+#             */
/*   Updated: 2024/11/09 03:27:36 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (len-- > 0 && *big != '\0')
	{
		i = 0;
		while (big[i] == little[i] && big[i] != '\0' && i <= len)
			i++;
		if (little[i] == '\0')
			return ((char *)big);
		big++;
	}
	if (little[i] == '\0')
		return ((char *)big);
	return (NULL);
}
