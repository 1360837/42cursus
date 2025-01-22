# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 20:07:57 by jiwnam            #+#    #+#              #
#    Updated: 2025/01/22 19:56:39 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifdef WITHBONUS
	NAME	= checker
	SRC		= $(BONUS_SRC)
else
	NAME	= push_swap
	SRC		= $(MAN_SRC)
endif

OBJ_DIR			= ./obj
PRINTF_DIR		= ./ft_printf
PRINTF_FILE		= $(PRINTF_DIR)/libftprintf.a

CC				= cc
CCFLAG			= -Wall -Wextra -Werror
RM				= rm
RMFLAG			= -rf

MAN_SRC			= push_swap.c		\
				  swap.c			

BONUS_SRC		=

OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all				: $(NAME)

$(NAME)			: $(OBJ) | $(PRINTF_FILE)
					$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -o $@

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
					$(CC) $(CCFLAG) -I./ft_printf -c $< -o $@

$(PRINTF_FILE)	:
					make -s -C $(PRINTF_DIR)

clean			:
					make -s -C $(PRINTF_DIR) clean
					$(RM) $(RMFLAG) $(OBJ_DIR)

fclean			: clean
					make -s -C $(PRINTF_DIR) fclean
					$(RM) $(RMFLAG) $(NAME)

re				: fclean all

bonus			:
				@make --no-print-directory WITHBONUS=1 all

.PHONY			: all clean fclean re bonus
