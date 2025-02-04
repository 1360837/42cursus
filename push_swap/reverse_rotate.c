/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:56:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/04 18:06:50 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = a->stack[0];
	while (idx < a->top)
	{
		a->stack[idx] = a->stack[idx + 1];
		idx++;
	}
	a->stack[idx] = tmp;
	write(1, "rra\n", 3);
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = b->stack[0];
	while (idx < b->top)
	{
		b->stack[idx] = b->stack[idx + 1];
		idx++;
	}
	b->stack[idx] = tmp;
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
