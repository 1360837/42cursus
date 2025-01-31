/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/31 15:45:08 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	static t_stack	*a;
	static t_stack	*b;
	int		idx;

	if (ac == 1)
		return (0);
	init_stack(a, ac - 1);
	init_stack(b, ac - 1);
	idx = 0;
	while (idx < ac)
	{
		if (!is_num(av[idx + 1]))
			print_error();
		a->stack[idx] = ft_atoi(av[idx + 1]);
		idx++;
	}
	push_swap(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && is_empty(b))
		return ;
	while (1)
	{
		if (is_empty(a) && is_sorted(b))
			break ;
		// a에서 제일 작은수를 찾아서 pb
	}
	while (!is_empty(b))
		pa(a, b);
	return ;
}

