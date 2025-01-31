/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:03 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/31 13:19:32 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *st, int size)
{
	st = malloc(sizeof(t_stack));
	if (!st)
		return (print_error());
	st->top = -1;
	st->stack = malloc(sizeof(int) * size);
	if (!st->stack)
		return (print_error());
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
