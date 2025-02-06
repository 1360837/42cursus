/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:20:38 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 18:13:11 by jiwnam           ###   ########.fr       */
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

void	radix_sort_a_to_b_3(t_stack *a, t_stack *b, int digit)
{
	int				size;
	unsigned int	data;

	size = a->top;
	while (size-- >= 0)
	{
		data = calculate_data(a, digit, 3);
		if (data == 0 || data == 1)
			pb(a, b);
		else
			ra(a);
		if (data == 1)
			rb(b);
	}
	while (!is_empty(a))
		pb(a, b);
}

void	radix_sort_b_to_a_3(t_stack *b, t_stack *a, int digit)
{
	int				size;
	unsigned int	data;

	size = b->top;
	while (size-- >= 0)
	{
		data = calculate_data(b, digit, 3);
		if (data == 0 || data == 1)
			pa(a, b);
		else
			rb(b);
		if (data == 1)
			ra(a);
	}
	while (!is_empty(b))
		pa(a, b);
}

void	radix_sort_a_to_b_4(t_stack *a, t_stack *b, int digit)
{
	int				size;
	unsigned int	data;

	size = a->top;
	while (size-- >= 0)
	{
		data = calculate_data(a, digit, 4);
		if (data == 0 || data == 1)
			pb(a, b);
		else
			ra(a);
		if (data == 1)
			rb(b);
	}
	while (!is_empty(a))
	{
		data = calculate_data(a, digit, 4);
		pb(a, b);
		if (data == 3)
			rb(b);
	}
}

void	radix_sort_b_to_a_4(t_stack *b, t_stack *a, int digit)
{
	int				size;
	unsigned int	data;

	size = b->top;
	while (size-- >= 0)
	{
		data = calculate_data(b, digit, 4);
		if (data == 0 || data == 1)
			pa(a, b);
		else
			rb(b);
		if (data == 1)
			ra(a);
	}
	while (!is_empty(b))
	{
		data = calculate_data(b, digit, 4);
		pa(a, b);
		if (data == 3)
			ra(a);
	}
}
