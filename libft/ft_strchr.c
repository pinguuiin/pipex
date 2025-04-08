/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:43:29 by piyu              #+#    #+#             */
/*   Updated: 2024/11/08 23:16:20 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)0;
	while (*(s + i))
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (*((unsigned char *)s + i) == (unsigned char)c)
		return ((char *)(s + i));
	else
		return (ptr);
}
