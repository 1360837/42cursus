/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:04:32 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 23:05:59 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checker(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		cmd_action(cmd, a, b);
		cmd = get_next_line(0);
	}
	if (is_sorted(a))
		return (1);
	return (0);
}

void	cmd_action(char *cmd, t_stack *a, t_stack *b)
{
	size_t	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (!ft_strncmp(cmd, "sa\n", cmd_len))
		sa(a, 0);
	if (!ft_strncmp(cmd, "sb\n", cmd_len))
		sb(b, 0);
	if (!ft_strncmp(cmd, "ss\n", cmd_len))
		ss(a, b, 0);
	if (!ft_strncmp(cmd, "pa\n", cmd_len))
		pa(a, b, 0);
	if (!ft_strncmp(cmd, "pb\n", cmd_len))
		pb(a, b, 0);
	if (!ft_strncmp(cmd, "ra\n", cmd_len))
		ra(a, 0);
	if (!ft_strncmp(cmd, "rb\n", cmd_len))
		rb(b, 0);
	if (!ft_strncmp(cmd, "rr\n", cmd_len))
		rr(a, b, 0);
	if (!ft_strncmp(cmd, "rra\n", cmd_len))
		rra(a, 0);
	if (!ft_strncmp(cmd, "rrb\n", cmd_len))
		rrb(b, 0);
	if (!ft_strncmp(cmd, "rrr\n", cmd_len))
		rrr(a, b, 0);
}

void	make_stack(t_stack **a, t_stack **b, char *av[], int size)
{
	unsigned int	*tmp_arr;

	tmp_arr = make_arr(av, size);
	if (!tmp_arr)
		print_error(NULL);
	*a = init_stack(size);
	*b = init_stack(size);
	if (!*a || !*b)
	{
		free_stack(*a, *b);
		print_error((void **)&tmp_arr);
	}
	stack_value(tmp_arr, *a, size);
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
		if (!str_tmp || !*str_tmp)
			return (tmp_free(str_tmp), print_error((void **)&arr), NULL);
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
