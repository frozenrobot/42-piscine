# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:33:01 by kgulati           #+#    #+#              #
#    Updated: 2021/04/26 15:11:59 by kgulati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
		srcs/ft_swap.c srcs/ft_strlen.c
OUT = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o \
		srcs/ft_strlen.o srcs/ft_swap.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I includes/ft.h -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	gcc -Wall -Wextra -Werror -I includes/ft.h -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	gcc -Wall -Wextra -Werror -I includes/ft.h -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	gcc -Wall -Wextra -Werror -I includes/ft.h -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	gcc -Wall -Wextra -Werror -I includes/ft.h -c srcs/ft_swap.c -o srcs/ft_swap.o
	ar rcs $(NAME) $(OUT)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all