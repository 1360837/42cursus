/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:38:35 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 21:29:47 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_arr(char *av[], int size)
{
	int		idx;
	int		*arr;
	char	**str_tmp;

	idx = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (*av)
	{
		str_tmp = ft_split(*av, ' ');
		if (!str_tmp)
			print_error((void **)&arr, NULL);
		while (*str_tmp)
		{
			if (!is_num(*str_tmp))
				print_error((void **)&arr, (void **)str_tmp);
			arr[idx++] = ft_atoi(*str_tmp);
		}
		tmp_free(str_tmp);
		av++;
	}
	return (arr);
}

void	stack_value(int *arr, t_stack *st, int size)
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
				print_error((void **)&arr, (void **)&st);
			j++;
		}
		push(st, num);
		i++;
	}
}

int	is_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	tmp_free(char **arr)
{
	size_t	idx;

	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}

int	count_nums(char *str)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		if (*str != ' ' && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*str == ' ')
			flag = 0;
		str++;
	}
	return (cnt);
}
