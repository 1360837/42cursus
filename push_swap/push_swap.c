/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 21:30:06 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	static t_stack	*a;
	static t_stack	*b;
	static int		cnt;
	static int		idx;
	int				*tmp_arr;

	if (ac == 1)
		return (0);
	while (*(av[idx]))
		cnt += count_nums(av[idx++]);
	tmp_arr = make_arr(av, cnt);
	if (!tmp_arr)
		print_error(NULL, NULL);
	a = init_stack(cnt);
	if (!a)
		print_error((void **)&tmp_arr, NULL);
	stack_value(tmp_arr, a, cnt);
	free(tmp_arr);
	b = init_stack(cnt);
	if (!b)
		print_error((void **)&a, NULL);
	push_swap(a, b);
}

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
