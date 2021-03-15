# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 01:58:21 by kyounkim          #+#    #+#              #
#    Updated: 2021/03/16 03:14:59 by kyounkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= ./libft/libft.a

AR			= ar
ARFLAGS		= rcs
INCS		= .
RM			= rm -f
LIBC		= ar rcs
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ./ft_printf.c \
			  ./print_type.c \
			  ./ft_printf_utils.c \
			  ./print_char.c \
			  ./print_str.c \
			  ./print_nbr.c

OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make all -C ./libft
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c $<

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C ./libft

fclean : clean
	$(RM) $(OBJS)
	make fclean -C ./libft

re : fclean all

.PHONY: clean fclean all re

