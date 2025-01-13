/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:09:40 by jiwnam            #+#    #+#             */
/*   Updated: 2024/10/16 21:55:38 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_digit(int n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		digit += 2;
		n = (n / 10) * -1;
	}
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char			*arr;
	size_t			digit;
	unsigned int	num;

	digit = count_digit(n);
	arr = malloc(digit + 1);
	if (arr == NULL)
		return (arr);
	num = (unsigned int)n;
	if (n < 0)
	{
		arr[0] = '-';
		num *= -1;
	}
	if (n == 0)
		arr[0] = '0';
	arr[digit--] = '\0';
	while (num > 0)
	{
		arr[digit--] = (num % 10) + '0';
		num /= 10;
	}
	return (arr);
}		
