/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:04:32 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 23:48:04 by jiwnam           ###   ########.fr       */
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
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(a))
		return (1);
	return (0);
}

void	cmd_action(char *cmd, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		sa(a, 0);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		sb(b, 0);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		ss(a, b, 0);
	else if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		pa(a, b, 0);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		pb(a, b, 0);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		ra(a, 0);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		rb(b, 0);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rr(a, b, 0);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rra(a, 0);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rrb(b, 0);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rrr(a, b, 0);
	else
		return (free_stack(a, b), print_error((void **)&cmd));
}

void	make_stack(t_stack **a, t_stack **b, char *av[], int size)
{
	unsigned int	*tmp_arr;

	tmp_arr = make_arr(av, size);
	if (!tmp_arr)
		print_error(NULL);
	*a = init_stack(size);
	if (!*a)
		print_error((void **)&tmp_arr);
	stack_value(tmp_arr, *a, size);
	free(tmp_arr);
	*b = init_stack(size);
	if (!*b)
	{
		free_stack(*a, NULL);
		print_error(NULL);
	}
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
