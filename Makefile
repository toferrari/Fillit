# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 12:29:19 by tferrari          #+#    #+#              #
#    Updated: 2016/12/11 11:40:47 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

SRC = 	main.c \
		ft_check_input.c \
		ft_check_tetra.c \
		ft_count_char.c \
		ft_count_tetra.c \
		ft_tab_2d.c \
		ft_check_piece.c

PT_O =	main.o \
		ft_check_tetra.o \
		ft_count_char.o \
		ft_check_input.o \
		ft_count_tetra.o \
		ft_tab_2d.o \
		ft_check_piece.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -Iinclude

clean:
	rm -f $(PT_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
