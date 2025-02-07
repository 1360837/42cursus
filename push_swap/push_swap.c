/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:40:45 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/08 02:07:42 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b, int flag)
{
	int	digit;
	int	max_digit;
	int	use_4;

	if (is_sorted(a))
		return ;
	digit = 1;
	max_digit = find_digit(a->top, 3);
	use_4 = check_4_radix_sort(max_digit, a->top);
	if (use_4)
		max_digit--;
	while (digit <= max_digit)
	{
		if (digit % 2 == 1)
			radix_sort_atob_3(a, b, digit++, flag);
		else if (digit % 2 == 0 && (digit < max_digit || use_4 == 0))
			radix_sort_btoa_3(b, a, digit++, flag);
		else
			radix_sort_btoa_4(b, a, digit++, flag);
	}
	if (digit % 2 == 0)
		radix_sort_btoa_3(b, a, digit++, flag);
}

t_stack	*make_stack(char *av[], int size)
{
	unsigned int	*tmp_arr;
	t_stack			*a;
	t_stack			*a_tmp;

	tmp_arr = make_arr(av, size);
	if (!tmp_arr)
		print_error(NULL);
	a = init_stack(size);
	a_tmp = init_stack(size);
	if (!a || !a_tmp)
	{
		free_stack(a, a_tmp);
		print_error((void **)&tmp_arr);
	}
	stack_value(tmp_arr, a_tmp, size);
	push_swap(a_tmp, a, 0);
	stack_value(tmp_arr, a, size);
	stack_idx_value(a, a_tmp);
	free_stack(a_tmp, NULL);
	free(tmp_arr);
	return (a);
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
			print_error((void **)&arr);
		str_idx = 0;
		while (str_idx < count_nums(*av))
		{
			if (!is_num(str_tmp[str_idx]))
				return (tmp_free(str_tmp), print_error((void **)&arr), NULL);
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
		num = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
				num++;
			else if (j != i && arr[j] == arr[i])
			{
				free_stack(st, NULL);
				print_error((void **)&arr);
			}
			j++;
		}
		push(st, num);
		i++;
	}
}

void	stack_idx_value(t_stack *a, t_stack *a_tmp)
{
	int				cnt;
	unsigned int	data;

	cnt = a_tmp->top;
	while (cnt >= 0)
	{
		data = a->stack[cnt];
		a->stack[cnt--] = a_tmp->stack[a_tmp->top - data];
	}
	a->top = a_tmp->top;
}
