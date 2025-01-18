# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:34:57 by jiwnam            #+#    #+#              #
#    Updated: 2025/01/18 18:27:35 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

OBJ_DIR			= ./obj

PRINTF_DIR		= ./ft_printf
PRINTF_FILE		= $(PRINTF_DIR)/libftprintf.a

CC				= cc
CCFLAG			= -Wall -Wextra -Werror
RM				= rm
RMFLAG			= -rf

SRC				= 

OBJ				= $(SRC:.c=.o)
				$(CC) $(CCFLAG) $^ -I./ft_printf -c $< -o $@

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
				$(CC) $(CCFLAG) -c 

all				: $(NAME)

$(NAME)			: $(OBJ) $(PRINTF_FILE)
				make -C $(PRINTF_DIR)
				$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -o $@

$(PRINTF_FILE)	:
				make -C $(PRINTF_DIR)

$(OBJ_DIR)		:
				mkdir -p $(OBJ_DIR)

bonus			: all

clean			:
				make -C $(PRINTF_DIR) clean
				$(RM) $(RMFLAG) $(OBJ_DIR)

fclean			: clean
				$(RM) $(RMFLAG) $(NAME)
				$(RM) $(RMFLAG) $(PRINTF_FILE)

re				: fclean all

.PHONY			: all clean fclean re bonus
