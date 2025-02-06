/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:20:38 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 21:44:51 by jiwnam           ###   ########.fr       */
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

void	radix_sort_atob_3(t_stack *a, t_stack *b, int digit, int flag)
{
	int				size;
	unsigned int	data;

	size = a->top;
	while (size-- >= 0)
	{
		data = calculate_data(a, digit, 3);
		if (data == 0 || data == 1)
			pb(a, b, flag);
		else
			ra(a, flag);
		if (data == 1)
			rb(b, flag);
	}
	while (!is_empty(a))
		pb(a, b, flag);
}

void	radix_sort_btoa_3(t_stack *b, t_stack *a, int digit, int flag)
{
	int				size;
	unsigned int	data;

	size = b->top;
	while (size-- >= 0)
	{
		data = calculate_data(b, digit, 3);
		if (data == 0 || data == 1)
			pa(a, b, flag);
		else
			rb(b, flag);
		if (data == 1)
			ra(a, flag);
	}
	while (!is_empty(b))
		pa(a, b, flag);
}

void	radix_sort_atob_4(t_stack *a, t_stack *b, int digit, int flag)
{
	int				size;
	unsigned int	data;

	size = a->top;
	while (size-- >= 0)
	{
		data = calculate_data(a, digit, 4);
		if (data == 0 || data == 1)
			pb(a, b, flag);
		else
			ra(a, flag);
		if (data == 1)
			rb(b, flag);
	}
	while (!is_empty(a))
	{
		data = calculate_data(a, digit, 4);
		pb(a, b, flag);
		if (data == 3)
			rb(b, flag);
	}
}

void	radix_sort_btoa_4(t_stack *b, t_stack *a, int digit, int flag)
{
	int				size;
	unsigned int	data;

	size = b->top;
	while (size-- >= 0)
	{
		data = calculate_data(b, digit, 4);
		if (data == 0 || data == 1)
			pa(a, b, flag);
		else
			rb(b, flag);
		if (data == 1)
			ra(a, flag);
	}
	while (!is_empty(b))
	{
		data = calculate_data(b, digit, 4);
		pa(a, b, flag);
		if (data == 3)
			ra(a, flag);
	}
}
