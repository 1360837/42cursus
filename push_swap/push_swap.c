/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/05 22:42:40 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	digit;
	int	max_digit;

	digit = 1;
	max_digit = find_digit(a->top, 4);
	if (is_sorted(a))
		return ;
	while (digit < max_digit)
	{
		radix_sort_a_to_b_4(a, b, digit++);
		radix_sort_b_to_a_4(b, a, digit++);
	}
	// max_digit인 경우 코딩
	return ;
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

void	print_error(void **a1, void **a2)
{
	if (a1 && *a1)
	{
		free(*a1);
		*a1 = NULL;
	}
	if (a1 && *a1)
	{
		free(*a2);
		*a2 = NULL;
	}
	write(2, "Error\n", 6);
	exit(0);
}
