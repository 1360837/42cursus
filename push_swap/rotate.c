/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:54:05 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/05 15:17:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	idx;

	idx = a->top;
	tmp = a->stack[a->top];
	while (idx > 0)
	{
		a->stack[idx] = a->stack[idx - 1];
		idx--;
	}
	a->stack[idx] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	tmp;
	int	idx;

	idx = b->top;
	tmp = b->stack[b->top];
	while (idx > 0)
	{
		b->stack[idx] = b->stack[idx - 1];
		idx--;
	}
	b->stack[idx] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
