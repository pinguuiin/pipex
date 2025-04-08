/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:43:02 by piyu              #+#    #+#             */
/*   Updated: 2024/11/12 15:43:38 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	i;
	char	*ptr;

	i = 0;
	if (start >= ft_strlen(s))
		sub_len = 0;
	else if (ft_strlen(s) >= start + len)
		sub_len = len;
	else
		sub_len = ft_strlen(s) - start;
	ptr = (char *)malloc((sub_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < sub_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
