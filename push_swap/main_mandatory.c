/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 21:33:13 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 21:31:53 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	static t_stack	*a;
	static t_stack	*b;
	static int		cnt;
	static int		idx;

	if (ac == 1)
		return (0);
	while (idx < ac - 1)
		cnt += count_nums(av[++idx]);
	if (cnt <= 5)
	{
		mini_push_swap(a, b, av + 1, cnt);
		return (0);
	}
	a = make_stack(av + 1, cnt);
	b = init_stack(cnt);
	if (!a || !b)
	{
		free_stack(a, b);
		print_error(NULL);
	}
	push_swap(a, b, 1);
	free_stack(a, b);
	return (0);
}
