# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 16:14:00 by jiwnam            #+#    #+#              #
#    Updated: 2025/02/25 22:03:03 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBFTDIR	= ./libft
LIBFTFILE	= libft.a

CC		= cc
CFLAG	= -Wall -Wextra -Werror
RM		= rm
RMFLAG	= -f
AR		= ar
ARFLAG	= crs

SRCS	= ft_printf.c			\
		  ft_printf_unum.c		\
		  get_next_line.c		\
		  get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -c $< -I$(LIBFTDIR) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
	$(AR) $(ARFLAG) $@ $?

clean:
	make -C $(LIBFTDIR) clean
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	make -C $(LIBFTDIR) fclean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

.PHONY: all clean fclean re
