/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 03:41:01 by piyu              #+#    #+#             */
/*   Updated: 2024/11/09 22:35:40 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		sign = 44 - *nptr;
		nptr++;
	}
	if (*nptr == 43 || *nptr == 45)
		return (0);
	while (*nptr >= 48 && *nptr <= 57)
	{
		num = (num * 10) + (*nptr - 48);
		if ((num > INT_MAX && sign == 1) || num > (long long)INT_MAX + 1)
			return (0);
		nptr++;
	}
	num *= sign;
	return (num);
}
