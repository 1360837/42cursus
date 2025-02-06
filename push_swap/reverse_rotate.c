/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:56:08 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 18:30:10 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int print_flag)
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
	if (print_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int print_flag)
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
	if (print_flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int print_flag)
{
	rra(a, print_flag);
	rrb(b, print_flag);
	if (print_flag)
		write(1, "rrr\n", 4);
}
