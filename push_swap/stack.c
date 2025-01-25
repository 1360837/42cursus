/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:03:03 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/25 19:40:10 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	init_stack(t_stack *st, int *top, int size)
{
	st = malloc(sizeof(t_stack));
	if (!st)
		return (print_error());
	st->top = -1;
	st->bottom = -1;
	st->stack = malloc(sizeof(int) * size);
	if (!st->stack)
		return (print_error());
}

void	push(int **stack, int data, int top, int bottom)
{

}

void	pop(int **stack, int data, int top, int bottom)
{

}
