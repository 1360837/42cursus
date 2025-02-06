/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:38:43 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 18:28:22 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int print_flag)
{
	int	tmp;

	if (a->top < 1)
		return ;
	tmp = a->stack[a->top];
	a->stack[a->top] = a->stack[(a->top) - 1];
	a->stack[(a->top) - 1] = tmp;
	if (print_flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print_flag)
{
	int	tmp;

	if (b->top < 1)
		return ;
	tmp = b->stack[b->top];
	b->stack[b->top] = b->stack[(b->top) - 1];
	b->stack[(b->top) - 1] = tmp;
	if (print_flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print_flag)
{
	sa(a, print_flag);
	sb(b, print_flag);
	if (print_flag)
		write(1, "ss\n", 3);
}
