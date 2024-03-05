# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:46:47 by wecorzo-          #+#    #+#              #
#    Updated: 2024/02/02 12:22:04 by wecorzo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CL_NAME = client
CL_SOURCES = client.c

CLB_NAME = client_bonus
CLB_SOURCES = client_bonus.c

SR_NAME = server
SR_SOURCES = server.c

SRB_NAME = server_bonus
SRB_SOURCES = server_bonus.c
LIBFT = ./Libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

start:
	@make all

$(LIBFT):
	@make -C ./Libft

all: $(LIBFT) $(CL_NAME) $(SR_NAME) 

bonus: $(LIBFT) $(CLB_NAME) $(SRB_NAME)

$(CL_NAME): $(CL_OBJECTS)
	@$(CC) $(CFLAGS) $(CL_SOURCES) $(LIBFT) -o $(CL_NAME)

$(CLB_NAME): $(CLB_OBJECTS)
	@$(CC) $(CFLAGS) $(CLB_SOURCES) $(LIBFT) -o $(CLB_NAME)

$(SR_NAME): $(SR_OBJECTS)
	@$(CC) $(CFLAGS) $(SR_SOURCES) $(LIBFT) -o $(SR_NAME)

$(SRB_NAME): $(SRB_OBJECTS)
	@$(CC) $(CFLAGS) $(SRB_SOURCES) $(LIBFT) -o $(SRB_NAME)

clean:
	@rm -f $(CL_NAME) $(SR_NAME) $(CLB_NAME) $(SRB_NAME)
	@make clean -C ./Libft

fclean: clean
	@rm -f $(CL_NAME) $(SR_NAME) $(CLB_NAME) $(SRB_NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re #bonus
