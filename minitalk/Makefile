# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwnam <jiwnam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 16:12:38 by jiwnam            #+#    #+#              #
#    Updated: 2025/01/13 18:57:51 by jiwnam           ###   ########.fr        #
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
RMFLAG		= -f

SERVER_SRC	= server.c

CLIENT_SRC	= client.c

SERVER_OBJ	= $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
CLIENT_OBJ	= $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))

all			: $(NAME)

$(NAME)		: $(PRINTF) $(OBJS) $(SERVER) $(CLIENT)

$(SERVER)	: 

$(CLIENT)	:

$(OBJ_DIR)	:
				mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	:
				$(CC) $(CCFLAG) -I./ft_printf -c $< -o $@



clean		:
				make -C $(PRINTF_DIR) clean
				$(RM) $(RMFLAG) $(OBJ_DIR)

fclean		: clean
				make -C $(PRINTF_DIR) fclean
				$(RM) $(RMFLAG) $(SERVER)
				$(RM) $(RMFLAG) $(CLIENT)

re			: fclean all

.PHONY		: all clean fclean re
