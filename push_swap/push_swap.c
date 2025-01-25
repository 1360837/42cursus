/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/25 20:55:36 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	int	*a;
	int	*b;

	if (ac == 1)
		return (0);
	init_stack(&a, &b, ac - 1, av);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

// void	init_stack(int **a, int **b, int size, char *arr[])
// {
// 	int	idx;

// 	idx = 0;
// 	*a = malloc(sizeof(int) * size);
// 	*b = malloc(sizeof(int) * size);
// 	if (!*a || !*b)
// 	{
// 		ft_free((void *)a, (void *)b);
// 		print_error();
// 	}
// 	while (idx < size)
// 	{
// 		(*a)[idx] = ft_atoi(arr[idx]);
// 		if ((*a)[idx] < 0)
// 			print_error();
// 	}
// }

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
