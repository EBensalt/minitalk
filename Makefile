# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebensalt <ebensalt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 02:16:29 by ebensalt          #+#    #+#              #
#    Updated: 2022/07/24 00:43:52 by ebensalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
NAME1	= client
C		= server.c \
		  ft_printf/ft_printf.c \
		  ft_printf/ft_puthexa.c \
		  ft_printf/ft_puthexap.c \
		  ft_printf/ft_putnbr.c \
		  ft_printf/ft_putstr.c \
		  ft_printf/ft_putunbr.c \
		  ft_printf/libft/ft_putchar_fd.c \
		  ft_printf/libft/ft_strlen.c \
		  ft_printf/libft/ft_strdup.c
C1		= client.c \
		  ft_printf/libft/ft_atoi.c
O		= $(C:.c=.o)
O1		= $(C1:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address
all		: $(NAME) $(NAME1)
$(NAME)	: $(O)
	$(CC) $(CFLAGS) $(O) -o $(NAME)
$(NAME1)	: $(O1)
	$(CC) $(CFLAGS) $(O1) -o $(NAME1)
clean	:
	rm -rf *.o */*.o */*/*.o
fclean	: clean
	rm -rf $(NAME) $(NAME1)
re		: fclean all
