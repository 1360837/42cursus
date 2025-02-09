/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:32:25 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/09 22:53:11 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <ft_printf.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				top;
	unsigned int	*stack;
}	t_stack;

// checker.c
int				checker(t_stack *a, t_stack *b);
void			cmd_action(char *cmd, t_stack *a, t_stack *b);
void			make_stack(t_stack **a, t_stack **b, char *av[], int size);
unsigned int	*make_arr(char *av[], int size);
void			stack_value(unsigned int *arr, t_stack *st, int size);

// checker_utils.c
int				is_num(char *str);
int				count_nums(char *str);
void			free_stack(t_stack *st1, t_stack *st2);
void			tmp_free(char **arr);
void			print_error(void **a);

// swap.c
void			sa(t_stack *a, int print_flag);
void			sb(t_stack *b, int print_flag);
void			ss(t_stack *a, t_stack *b, int print_flag);

// push.c
void			pa(t_stack *a, t_stack *b, int print_flag);
void			pb(t_stack *a, t_stack *b, int print_flag);

// rotate.c
void			ra(t_stack *a, int print_flag);
void			rb(t_stack *b, int print_flag);
void			rr(t_stack *a, t_stack *b, int print_flag);

// reverse_rotate.c
void			rra(t_stack *a, int print_flag);
void			rrb(t_stack *b, int print_flag);
void			rrr(t_stack *a, t_stack *b, int print_flag);

// stack.c
t_stack			*init_stack(int size);
void			push(t_stack *st, int data);
int				pop(t_stack *st);
int				is_empty(t_stack *st);
int				is_sorted(t_stack *a);

#endif
