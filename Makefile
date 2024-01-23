# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/01/23 10:18:42 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CL_NAME = client
CL_SOURCES = client.c

SR_NAME = server
SR_SOURCES = server.c

LIBFT = ./Libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

start:
	@make all

$(LIBFT):
	@make -C ./Libft

all: $(LIBFT) $(CL_NAME) $(SR_NAME)

$(CL_NAME): $(CL_OBJECTS)
	@$(CC) $(CFLAGS) $(CL_SOURCES) $(LIBFT) -o $(CL_NAME)

$(SR_NAME): $(SR_OBJECTS)
	@$(CC) $(CFLAGS) $(SR_SOURCES) $(LIBFT) -o $(SR_NAME)

clean:
	@rm -f $(CL_OBJECTS) $(SR_NAME)
	@make clean -C ./Libft

fclean: clean
	@rm -f $(CL_NAME) $(SR_NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re #bonus
