/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:16:57 by piyu              #+#    #+#             */
/*   Updated: 2024/11/08 23:31:55 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)0;
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if (*(unsigned char *)s == (unsigned char)c)
		ptr = (char *)s;
	return (ptr);
}
