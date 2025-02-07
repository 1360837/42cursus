/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:08:22 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/08 02:07:29 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	calculate_data(t_stack *st, int digit, int radix)
{
	unsigned int	data;
	int				digit_idx;

	data = st->stack[st->top];
	digit_idx = 1;
	while (digit_idx++ < digit)
		data /= 3;
	data %= radix;
	return (data);
}

int	check_4_radix_sort(int max_digit, int size)
{
	int	num;
	int	digit;

	if (max_digit % 2 == 0)
		return (0);
	num = 1;
	digit = 1;
	while (digit++ <= max_digit - 2)
		num *= 3;
	if (num * 3 < size && num * 4 >= size)
		return (1);
	return (0);
}

int	find_digit(int size, int radix)
{
	int	return_value;

	return_value = 0;
	while (size > 0)
	{
		return_value++;
		size /= radix;
	}
	return (return_value);
}
