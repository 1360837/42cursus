/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/31 15:22:41 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	int		idx;

	if (ac == 1)
		return (0);
	init_stack(a, ac - 1);
	init_stack(b, ac - 1);
	idx = 0;
	while (idx < ac)
	{
		a->stack[idx] = av[idx + 1];
		idx++;
	}
	push_swap(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && is_empty(b))
		return ;

}
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	is_sorted(t_stack *a)
{
	int	idx;

	idx = 0;
	while (idx < a->top)
	{
		if (a->stack[idx] < a->stack[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void	ft_free(void **a1, void **a2)
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
}
