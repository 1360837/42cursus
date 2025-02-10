/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:52:19 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/10 15:58:39 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_push_swap(t_stack *a, t_stack *b, char *av[], int size)
{
	unsigned int	*tmp_arr;

	tmp_arr = make_arr(av, size);
	if (!tmp_arr)
		print_error(NULL);
	a = init_stack(size);
	b = init_stack(size);
	if (!a || !b)
	{
		free_stack(a, b);
		print_error((void **)&tmp_arr);
	}
	stack_value(tmp_arr, a, b, size);
	free(tmp_arr);
	if (size == 2)
		push_swap_2(a);
	if (size == 3)
		push_swap_3(a);
	if (size == 4)
		push_swap_4(a, b);
	if (size == 5)
		push_swap_5(a, b);
	free_stack(a, b);
	return ;
}

void	push_swap_2(t_stack *a)
{
	if (is_sorted(a))
		return ;
	else
		sa(a, 1);
}

void	push_swap_3(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (a->stack[2] > a->stack[1] && a->stack[2] > a->stack[0])
		ra(a, 1);
	else if (a->stack[1] > a->stack[2] && a->stack[1] > a->stack[0])
		rra(a, 1);
	if (is_sorted(a))
		return ;
	sa(a, 1);
	return ;
}

void	push_swap_4(t_stack *a, t_stack *b)
{
	int	idx;

	idx = 0;
	if (is_sorted(a))
		return ;
	while (idx < 4)
	{
		if (a->stack[a->top] <= 1)
			pb(a, b, 1);
		else
			ra(a, 1);
		idx++;
	}
	push_swap_2(a);
	if (b->stack[b->top] == 0)
		rb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	return ;
}

void	push_swap_5(t_stack *a, t_stack *b)
{
	int	idx;

	idx = 0;
	if (is_sorted(a))
		return ;
	while (idx < 5)
	{
		if (a->stack[a->top] < 2)
			pb(a, b, 1);
		else
			ra(a, 1);
		idx++;
	}
	push_swap_3(a);
	if (b->stack[b->top] == 0)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
}
