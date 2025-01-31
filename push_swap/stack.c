/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:03 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/31 15:47:46 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *st, int size)
{
	int	idx;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (print_error());
	st->top = -1;
	st->stack = malloc(sizeof(int) * size);
	if (!st->stack)
		return (print_error());
	idx = 0;
	while (idx < size)
		st->stack[idx] = 0;
}

void	push(t_stack *st, int data)
{
	st->top++;
	st->stack[st->top] = data;
}

int	pop(t_stack *st)
{
	return (st->stack[st->top--]);
}

int	is_empty(t_stack *st)
{
	return (st->top == -1);
}

int	is_sorted(t_stack *a)
{
	int	idx;

	idx = 0;
	while (idx < a->top)
	{
		if (a->stack[idx] < a->stack[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}
