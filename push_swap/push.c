/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:47:22 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/31 13:14:35 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	data;

	data = pop(b);
	push(a, data);
}

void	pb(t_stack *a, t_stack *b)
{
	int	data;

	data = pop(a);
	push(b, data);
}
