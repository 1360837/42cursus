/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:26:17 by jiwnam            #+#    #+#             */
/*   Updated: 2025/01/25 19:40:18 by jiwnam           ###   ########.fr       */
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
	int	bottom;
	int	*stack;
}	t_stack;

//push_swap.c
void	print_error(void);
void	init_stack(int **a, int **b, int size, char *arr[]);
void	ft_free(void **a1, void **a2);

//swap.c
void	sa(int **a);
void	sb(int **b);
void	ss(int **a, int **b);

//push.c
void	pa(int **a);
void	pb(int **b);

//rotate.c
void	ra(int **a);
void	rb(int **a);
void	rr(int **a, int **b);

//reverse_rotate.c
void	rra(int **a);
void	rrb(int **b);
void	rrr(int **a, int **b);

//stack.c
void	push(int **stack, int data, int top, int bottom);
void	pop(int **stack, int data, int top, int bottom);

#endif
