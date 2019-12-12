# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 12:26:27 by osalmine          #+#    #+#              #
#    Updated: 2019/12/12 12:14:28 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SOURCE = fillit.c verify.c read.c additional.c solve.c
OBJ = $(SOURCE:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
INCLUDE = fillit.h
LIBFT = libft.a

all:
	make -C libft
	cp libft/$(LIBFT) .
	gcc $(FLAGS) -c $(SOURCE) -I$(INCLUDE)
	gcc -o $(NAME) $(OBJ) $(LIBFT)
	rm -f $(LIBFT)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
