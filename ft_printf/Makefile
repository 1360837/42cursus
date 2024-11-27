# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 16:14:00 by jiwnam            #+#    #+#              #
#    Updated: 2024/11/27 16:24:31 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc
CFLAG=-Wall -Wextra -Werror
RM=rm
RMFLAGS=-f
AR=ar
ARFLAG=crs

INCLUDES=./ft_printf.h

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	$(RM) $(RMFLAG) $(OBJ)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)

re: fclean all

$(NAME): $(OBJS)
		   $(AR) $(ARFLAG) $@ $^

.PHONY: all clean fclean re
