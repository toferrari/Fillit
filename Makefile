# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 12:29:19 by tferrari          #+#    #+#              #
#    Updated: 2016/12/14 16:30:13 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

SRC = 	srcs/main.c \
		srcs/ft_check_coor.c \
		srcs/ft_check_input.c \
		srcs/ft_check_piece.c \
		srcs/ft_check_tetra.c \
		srcs/ft_coor_tetra_zero.c \
		srcs/ft_coor_tetra.c \
		srcs/ft_count_char.c \
		srcs/ft_count_tetra.c \
		srcs/ft_display.c \
		srcs/ft_resolution.c \
		srcs/ft_sqrt_up.c \
		srcs/ft_tab_2d.c \
		srcs/ft_try_tetra.c

OBJ =	main.o \
		ft_check_coor.o \
		ft_check_input.o \
		ft_check_piece.o \
		ft_check_tetra.o \
		ft_coor_tetra_zero.o \
		ft_coor_tetra.o \
		ft_count_char.o \
		ft_count_tetra.o \
		ft_display.o \
		ft_resolution.o \
		ft_sqrt_up.o \
		ft_tab_2d.o \
		ft_try_tetra.o

LIB = -L. -lft

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -Iincludes/
	gcc -o $(NAME) $(OBJ) $(LIB) -Iincludes/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
