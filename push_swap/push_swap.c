/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/06 19:08:09 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(t_stack *a, t_stack *b)
// {
// 	int	digit;
// 	int	max_digit;

// 	digit = 1;
// 	max_digit = find_digit(a->top, 4);
// 	if (is_sorted(a))
// 		return ;
// 	while (digit <= max_digit)
// 	{
// 		radix_sort_a_to_b_3(a, b, digit++);
// 		radix_sort_b_to_a_3(b, a, digit++);
// 	}
// 	// if (digit == max_digit)
// 	// {
// 	// 	if (select_3or4(a, digit) == 3)
// 	// 		radix_sort_a_to_b_3(a, b, digit++);
// 	// 	else
// 	// 		radix_sort_a_to_b_4(a, b, digit++);
// 	// 	radix_sort_b_to_a_3(b, a, digit);
// 	// }
// 	// else
// 	// {
// 	// 	radix_sort_a_to_b_3(a, b, digit++);
// 	// 	if (select_3or4(b, digit) == 3)
// 	// 		radix_sort_b_to_a_3(b, a, digit);
// 	// 	else
// 	// 		radix_sort_b_to_a_4(b, a, digit);
// 	// }
// 	return ;
// }

void	push_swap(t_stack *a, t_stack *b, int print_flag)
{
	radix_sort_a_to_b_3(a, b, 1, print_flag);
	radix_sort_b_to_a_3(b, a, 2, print_flag);
	radix_sort_a_to_b_3(a, b, 3, print_flag);
	radix_sort_b_to_a_4(b, a, 4, print_flag);
}

unsigned int	*make_arr(char *av[], int size)
{
	int				str_idx;
	unsigned int	*arr;
	char			**str_tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (*av)
	{
		str_tmp = ft_split(*av, ' ');
		if (!str_tmp)
			print_error((void **)&arr, NULL);
		str_idx = 0;
		while (str_idx < count_nums(*av))
		{
			if (!is_num(str_tmp[str_idx]))
				print_error((void **)&arr, (void **)str_tmp);
			arr[--size] = ft_atoi(str_tmp[str_idx++]);
		}
		tmp_free(str_tmp);
		av++;
	}
	return (arr);
}

void	stack_value(unsigned int *arr, t_stack *st, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < size)
	{
		j = 0;
		num = 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
				num++;
			else if (j != i && arr[j] == arr[i])
				print_error((void **)&arr, (void **)&st);
			j++;
		}
		push(st, num);
		i++;
	}
}

int	find_digit(int size, int radix)
{
	int	return_value;

	return_value = 1;
	while (size > 0)
	{
		return_value++;
		size /= radix;
	}
	return (return_value);
}

