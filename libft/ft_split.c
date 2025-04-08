/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 00:17:09 by piyu              #+#    #+#             */
/*   Updated: 2024/11/13 05:18:25 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] && s[i + 1] == c) || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char	**new_str(char **arr, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < word_count(s, c) && s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			arr[j] = ft_substr(s, i, word_len(s + i, c));
			if (arr[j] == NULL)
			{
				while (j-- >= 0)
					free(arr[j + 1]);
				free(arr);
				return (NULL);
			}
			i += word_len(s + i, c);
			j++;
		}
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		row;
	char	**arr;

	row = word_count(s, c);
	arr = (char **)malloc((row + 1) * sizeof(char *));
	if (arr == NULL || !s)
		return (NULL);
	return (new_str(arr, s, c));
}
