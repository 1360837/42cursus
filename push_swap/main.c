/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:33:13 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 21:46:35 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	static t_stack	*a;
	static t_stack	*b;
	static int		cnt;
	static int		idx;
	unsigned int	*tmp_arr;

	if (ac == 1)
		return (0);
	while (idx < ac - 1)
		cnt += count_nums(av[++idx]);
	tmp_arr = make_arr(av + 1, cnt);
	if (!tmp_arr)
		print_error(NULL);
	a = init_stack(cnt);
	if (!a)
		print_error((void **)&tmp_arr);
	stack_value(tmp_arr, a, cnt);
	free(tmp_arr);
	b = init_stack(cnt);
	if (!b)
		print_error(NULL);
	if (is_sorted(a))
		return (0);
	push_swap(a, b, 1);
	free_stack(&a, &b);
}

t_stack	*make_stack()
