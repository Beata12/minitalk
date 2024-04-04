# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 07:41:04 by bmarek            #+#    #+#              #
#    Updated: 2024/02/17 10:53:03 by bmarek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LDFLAGS =

all: server client 

bonus: server client

server: server.o server_utils.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

client: client.o client_utils.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:	
	rm -f
	
fclean:
	rm -f *.o server client

re: fclean all

.PHONY: all bonus clean fclean re
