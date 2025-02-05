/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:38:35 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/05 22:40:08 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int	str_len;

	if (ft_strncmp(str, "-2147483648", 11) == 0)
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	str_len = ft_strlen(str);
	if (str_len > 10)
		return (0);
	if (str_len == 10 && ft_strncmp(str, "2147483647", str_len) > 0)
		return (0);
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

void	free_stack(t_stack **st1, t_stack **st2)
{
	if ((*st1)->stack)
		free((*st1)->stack);
	free(*st1);
	*st1 = NULL;
	if ((*st2)->stack)
		free((*st2)->stack);
	free(*st2);
}
