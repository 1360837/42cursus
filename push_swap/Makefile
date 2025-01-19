# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 20:07:57 by jiwnam            #+#    #+#              #
#    Updated: 2025/01/19 20:33:41 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

OJB_DIR			= ./obj

PRINTF_DIR		= ./ft_printf
PRINTF_FILE		= $(PRINTF_DIR)/libftprintf.a

CC				= cc
CCFLAG			= -Wall -Wextra -Werror
RM				= rm
RMFLAG			= -rf

SRC				=

BONUS_SRC		=

all				: $(NAME)

$(NAME)			: $(OBJ) | $(PRINTF_FILE)
					$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -o $@

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
					$(CC) $(CCFLAG) -I./ft_printf -c $< -o $@

$(PRINTF_FILE)	:
					make -C $(PRINTF_DIR)

clean			:
					make -C $(PRINTF_DIR) clean
					$(RM) $(RMFLAG) $(OBJ_DIR)

fclean			: clean
					$(RM) $(RMFLAG) $(PRINTF_FILE)
					$(RM) $(RMFLAG) $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
