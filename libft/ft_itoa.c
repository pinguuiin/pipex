/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piyu <piyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:55:05 by piyu              #+#    #+#             */
/*   Updated: 2024/11/14 00:12:45 by piyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int	temp;
	int	num;

	num = 1;
	temp = n;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		sign_digit;
	char	*ptr;

	digit = count_digit(n);
	if (n >= 0)
		sign_digit = 0;
	else
		sign_digit = 1;
	ptr = (char *)malloc((digit + sign_digit + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[digit + sign_digit] = '\0';
	while (--digit >= 0)
	{
		ptr[digit + sign_digit] = ((1 - 2 * (long)sign_digit) \
		* (long)n) % 10 + 48;
		n /= 10;
	}
	if (sign_digit == 1)
		ptr[0] = 45;
	return (ptr);
}
