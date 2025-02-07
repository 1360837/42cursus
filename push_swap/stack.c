/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:03 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/08 00:36:23 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int size)
{
	t_stack	*st;
	int		idx;

	st = malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->top = -1;
	st->stack = malloc(sizeof(int) * size);
	if (!st->stack)
	{
		free(st);
		return (NULL);
	}
	idx = 0;
	while (idx < size)
		st->stack[idx++] = 0;
	return (st);
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
