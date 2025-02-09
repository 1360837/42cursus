/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:32:10 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 22:57:35 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	make_stack(&a, &b, av + 1, cnt);
	if (checker(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a, b);
}
