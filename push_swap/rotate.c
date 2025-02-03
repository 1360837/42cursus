/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:54:05 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/03 17:06:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = a->stack[0];
	while (idx < a->top)
		a->stack[idx] = a->stack[idx + 1];
	a->stack[idx] = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int	tmp;
	int	idx;

	idx = 0;
	tmp = b->stack[0];
	while (idx < b->top)
		b->stack[idx] = b->stack[idx + 1];
	b->stack[idx] = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
