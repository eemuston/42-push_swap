# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eemuston <eemuston@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:14:40 by eemuston          #+#    #+#              #
#    Updated: 2023/02/15 19:13:32 by eemuston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = push_swap

NAME = push_swap.a

FLAGS = -Wall -Werror -Wextra

HEADER = -I push_swap.h

SRCS = push_swap.c push.c rotate.c swap_and_rrr.c is_sorted.c \
utils.c errors.c small_sort.c double_operations.c utils_two.c \
convert.c radix_sort.c my_atoi.c

OBJ = push_swap.o push.o rotate.o swap_and_rrr.o is_sorted.o \
utils.o errors.o small_sort.o double_operations.o utils_two.o \
convert.o radix_sort.o my_atoi.o

all: $(NAME)

$(NAME):
		$(MAKE) -C ./libft
		cp libft/libft.a push_swap.a
		cc -c $(FLAGS) $(HEADER) $(SRCS)
		ar rc $(NAME) $(OBJ)
		cc $(SRCS) $(NAME) -o $(EXE)
clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJ)
fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME) $(EXE) clean
re: fclean all