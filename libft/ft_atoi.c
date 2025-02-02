/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 22:59:04 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 16:31:44 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int		num;
	int		sign;
	size_t	idx;

	idx = 0;
	num = 0;
	sign = 1;
	while (is_space(*(nptr + idx)))
		idx++;
	if (*(nptr + idx) == '-')
		sign *= -1;
	if (*(nptr + idx) == '-' || *(nptr + idx) == '+')
		idx++;
	while (is_num(*(nptr + idx)))
	{
		num = (num * 10) + (*((char *)nptr + idx) - '0');
		idx++;
	}
	return (num * sign);
}
