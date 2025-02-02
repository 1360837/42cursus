/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 21:35:38 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	while (1)
	{
		if (is_sorted(a) && is_empty(b))
			return ;
		// radix sort
	}
	return ;
}

void	print_error(void **a1, void **a2)
{
	if (a1 && *a1)
	{
		free(*a1);
		*a1 = NULL;
	}
	if (a1 && *a1)
	{
		free(*a2);
		*a2 = NULL;
	}
	write(2, "Error\n", 6);
	exit(0);
}
