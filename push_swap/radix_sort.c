/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:20:38 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/05 22:40:08 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_a_to_b_4(t_stack *a, t_stack *b, int digit)
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
		while (digit_idx++ < digit)
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
		while (digit_idx++ < digit)
			data /= 4;
		data %= 4;
		pb(a, b);
		if (data == 3)
			rb(b);
		idx++;
	}
}

void	radix_sort_b_to_a_4(t_stack *b, t_stack *a, int digit)
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
			rb(b);
		if (data == 1)
			ra(a);
		idx++;
	}
	size = b->top;
	idx = 0;
	while (idx <= size)
	{
		data = b->stack[b->top];
		digit_idx = 1;
		while (digit_idx++ < digit)
			data /= 4;
		data %= 4;
		pa(a, b);
		if (data == 3)
			ra(a);
		idx++;
	}
}
