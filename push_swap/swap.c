/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:38:43 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/25 20:47:31 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a->top < 1)
		return ;
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[(a->top) - 1];
	a->stack[(a->top) - 1] = tmp;
	return ;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b->top < 1)
		return ;
	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[(b->top) - 1];
	b->stack[(b->top) - 1] = tmp;
	return ;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
