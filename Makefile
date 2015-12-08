# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:57:46 by pabril            #+#    #+#              #
#    Updated: 2015/12/08 10:37:29 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
NAME = fillit
SRC = main.c \
	  min_size_square.c \
	  store_pieces.c \
	  check_valid_pieces.c \
#	  resolution.c

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	@echo "building binary file"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -L libft -l ft

clean:
	@make clean -C libft/

fclean: clean
	@echo "delete $(NAME)"
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

