# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 19:21:43 by omadali           #+#    #+#              #
#    Updated: 2024/12/13 21:02:42 by omadali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
SERVER	= server
CLIENT	= client
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.c
	$(CC) $(CFLAGS) -o server server.c

$(CLIENT): client.c
	$(CC) $(CFLAGS) -o client client.c

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all $(NAME) clean fclean re