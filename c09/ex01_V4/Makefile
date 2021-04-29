# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgulati <kgulati@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 12:05:49 by kgulati           #+#    #+#              #
#    Updated: 2021/04/27 12:27:02 by kgulati          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
		srcs/ft_swap.c srcs/ft_strlen.c
OUT = srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o \
		srcs/ft_strlen.o srcs/ft_swap.o
INCLUDES = includes/

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c srcs/ft_swap.c -o srcs/ft_swap.o
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all