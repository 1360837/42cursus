/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/04 18:07:31 by jiwnam           ###   ########.fr       */
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
	while (digit <= max_digit) // 조건문 수정필요 (최적화)
	{
		radix_sort_a_to_b(a, b, digit++);
		radix_sort_b_to_a(b, a, digit++);
	}
	return ;
}

void	radix_sort_a_to_b(t_stack *a, t_stack *b, int digit)
{
	int	size;
	int	idx;
	int	digit_idx;
	int	data;

	size = a->top;
	idx = 0;
	while (idx <= size)
	{
		data = a->stack[a->top];
		digit_idx = 1;
		while (digit_idx < digit)
			data /= 4;
		data %= 4;
		if (data == 0 || data == 1)
			pb(a, b);
		else
			ra(a);
		if (data == 1)
			rb(b);
		idx++;
	}
	size = a->top;
	idx = 0;
	while (idx <= size)
	{
		data = a->stack[a->top];
		digit_idx = 1;
		while (digit_idx < digit)
			data /= 4;
		data %= 4;
		pb(a, b);
		if (data == 3)
			rb(b);
		idx++;
	}
}

void	radix_sort_b_to_a(t_stack *b, t_stack *a, int digit)
{
	int	size;
	int	idx;
	int	digit_idx;
	int	data;

	size = b->top;
	idx = 0;
	while (idx <= size)
	{
		data = b->stack[b->top];
		digit_idx = 1;
		while (digit_idx++ < digit)
			data /= 4;
		data %= 4;
		if (data == 0 || data == 1)
			pa(a, b);
		else
			rb(a);
		if (data == 1)
			ra(b);
		idx++;
	}
	size = b->top;
	idx = 0;
	while (idx <= size)
	{
		data = b->stack[b->top];
		digit_idx = 1;
		while (digit_idx < digit)
			data /= 4;
		data %= 4;
		pa(a, b);
		if (data == 3)
			ra(b);
		idx++;
	}
}

int	find_digit(int size, int radix)
{
	int return_value;

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
