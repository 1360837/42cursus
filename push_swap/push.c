/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:47:22 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/03 16:59:59 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	data;

	if (is_empty(b))
		return ;
	data = pop(b);
	push(a, data);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	data;

	if (is_empty(a))
		return ;
	data = pop(a);
	push(b, data);
	write(1, "pb\n", 3);
}
