# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:12:38 by jiwnam            #+#    #+#              #
#    Updated: 2025/01/20 19:03:10 by jiwnam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
SERVER		= server
CLIENT		= client

OBJ_DIR		= ./obj

PRINTF_DIR	= ./ft_printf
PRINTF_FILE	= $(PRINTF_DIR)/libftprintf.a

CC			= cc
CCFLAG		= -Wall -Wextra -Werror
RM			= rm
RMFLAG		= -rf

ifdef WITH_BONUS
	SERVER_SRC	= mini_server_bonus.c
	CLIENT_SRC	= mini_client_bonus.c
else
	SERVER_SRC	= mini_server.c
	CLIENT_SRC	= mini_client.c
endif

SERVER_OBJ	= $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
CLIENT_OBJ	= $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))

all			: $(NAME)

$(NAME)		: $(SERVER) $(CLIENT)

$(PRINTF_FILE)	:
			@make -s -C $(PRINTF_DIR)

$(SERVER)	: $(SERVER_OBJ) | $(PRINTF_FILE)
				$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -o $@ 

$(CLIENT)	: $(CLIENT_OBJ) $(PRINTF_FILE)
				$(CC) $(CCFLAG) $^ -L./ft_printf -lftprintf -o $@ 

$(OBJ_DIR)	:
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	: %.c | $(OBJ_DIR)
				$(CC) $(CCFLAG) -I./ft_printf -c $< -o $@

bonus		:
				@make --no-print-directory  WITH_BONUS=1 all

clean		:
				@make -s -C $(PRINTF_DIR) clean
				@$(RM) $(RMFLAG) $(OBJ_DIR)

fclean		: clean
				@$(RM) $(RMFLAG) $(PRINTF_FILE)
				@$(RM) $(RMFLAG) $(SERVER)
				@$(RM) $(RMFLAG) $(CLIENT)

re			: fclean all

.PHONY		: all clean fclean re bonus
