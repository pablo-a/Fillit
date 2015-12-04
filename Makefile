# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:57:46 by pabril            #+#    #+#              #
#    Updated: 2015/12/04 13:26:00 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
NAME = fillit
SRC = main.c \
	  min_size_square.c

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -L libft -l ft

clean:
	@echo "delete *.o"
	@rm -f *.o

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)

re: fclean all

