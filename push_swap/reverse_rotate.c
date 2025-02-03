/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:56:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/03 17:07:28 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	idx;

	idx = a->top;
	tmp = a->stack[a->top];
	while (idx > 0)
		a->stack[idx] = a->stack[idx - 1];
	a->stack[idx] = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	idx;

	idx = b->top;
	tmp = b->stack[b->top];
	while (idx > 0)
		b->stack[idx] = b->stack[idx - 1];
	b->stack[idx] = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
