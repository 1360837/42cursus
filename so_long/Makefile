# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 17:34:57 by jiwnam            #+#    #+#              #
#    Updated: 2025/02/15 18:45:49 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

OBJ_DIR			= ./obj

PRINTF_DIR		= ./ft_printf
PRINTF_FILE		= $(PRINTF_DIR)/libftprintf.a

CC				= cc
CCFLAG			= -Wall -Wextra -Werror -g
RM				= rm
RMFLAG			= -rf

SRC				= main.c			\
				  window.c			\
				  hook.c			\



OBJ				= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
				$(CC) $(CCFLAG)  -I./ft_printf -I./minilibx-linux -c $< -o $@

all				: $(NAME)

$(NAME)			: $(OBJ) $(PRINTF_FILE)
				$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz -o $@

$(PRINTF_FILE)	:
				@make -s -C $(PRINTF_DIR)

$(OBJ_DIR)		:
				@mkdir -p $(OBJ_DIR)

clean			:
				@make -s -C $(PRINTF_DIR) clean
				@$(RM) $(RMFLAG) $(OBJ_DIR)

fclean			: clean
				@make -s -C $(PRINTF_DIR) fclean
				@$(RM) $(RMFLAG) $(NAME)

re				: fclean all

.PHONY			: all clean fclean re bonus
