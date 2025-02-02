/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:26:17 by jiwnam            #+#    #+#             */
/*   Updated: 2025/02/02 20:33:33 by jiwnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_printf.h>
# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	top;
	int	*stack;
}	t_stack;

//push_swap.c
void	push_swap(t_stack *a, t_stack *b);
int		count_nums(char *str);

//push_swap_utils.c
void	print_error(void **a1, void **a2);
int		is_num(char *str);

//swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

//rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//reverse_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//stack.c
t_stack	*init_stack(int size);
void	push(t_stack *st, int data);
int		pop(t_stack *st);
int		is_empty(t_stack *st);
int		is_sorted(t_stack *a);

#endif
