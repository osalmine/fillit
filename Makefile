# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osalmine <osalmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 12:26:27 by osalmine          #+#    #+#              #
#    Updated: 2019/12/15 14:49:45 by osalmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SOURCE = fillit.c verify.c read.c additional.c solve.c map.c
OBJ = $(SOURCE:%.c=%.o)
FLAGS = -Wall -Werror -Wextra
INCLUDE = fillit.h
LIBFT = libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@cp libft/$(LIBFT) .
	@gcc $(FLAGS) -c $(SOURCE) -I$(INCLUDE)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)
	@rm -f $(LIBFT)
	@echo Compiled

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo Cleaned

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
