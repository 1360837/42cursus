/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/03 18:08:30 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	size;
	int	digit;
	int	max_digit;

	size = a->top;
	digit = 1;
	max_digit = find_digit(size, 4);
	while (1)
	{
		if (is_sorted(a, 1) && is_empty(b))
			return ;
		// radix sort
	}
	return ;
}

void	radix_sort(t_stack *a, t_stack *b)
{

}

int	find_digit(int size, int radix)
{
	int return_value;

	return_value = 0;
	while (size > 0)
	{
		return_value++;
		size /= radix;
	}
	return (return_value);
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
