# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyounkim <kyounkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 12:01:12 by kyounkim          #+#    #+#              #
#    Updated: 2021/08/26 12:01:12 by kyounkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_PS =	./ps_srcs/push_swap.c \
			./ps_srcs/get_op_list.c \
			./ps_srcs/get_pivot.c \
			./ps_srcs/get_value_in_stack.c \
			./ps_srcs/main_sort_a.c \
			./ps_srcs/main_sort_b.c \
			./ps_srcs/minimize_op_list.c \
			./ps_srcs/print_op_list.c \
			./ps_srcs/quick_sort.c \
			./ps_srcs/size_discord_a.c \
			./ps_srcs/size_discord_b.c \
			./ps_srcs/sort_just_six.c \
			./ps_srcs/sort_just_three_a.c \
			./ps_srcs/sort_just_three_b.c \
			./ps_srcs/init_count.c \
			./ps_srcs/exe_rrr.c

SRCS_CH =	./ck_srcs/checker.c \
			./ck_srcs/get_next_line.c

SRCS_CM =	./common_srcs/check_argv_and_add_stack.c \
			./common_srcs/free_stack_operation.c \
			./common_srcs/ft_atoll.c \
			./common_srcs/ft_strcmp.c \
			./common_srcs/ft_strdup.c \
			./common_srcs/ft_strlen.c \
			./common_srcs/mgmt_op_list.c \
			./common_srcs/mgmt_stack.c \
			./common_srcs/op_function.c \
			./common_srcs/sorted_check.c

OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CH = $(SRCS_CH:.c=.o)
OBJS_CM = $(SRCS_CM:.c=.o)

all : $(NAME_PS) $(NAME_CH)

$(NAME_PS) : $(OBJS_PS) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_PS) $(OBJS_PS) $(OBJS_CM)

$(NAME_CH) : $(OBJS_CH) $(OBJS_CM)
		$(CC) $(CFLAGS) -o $(NAME_CH) $(OBJS_CH) $(OBJS_CM)

clean :
		$(RM) $(OBJS_PS) $(OBJS_CH) $(OBJS_CM)

fclean : clean
		$(RM) $(NAME_PS) $(NAME_CH)

re : fclean all

.PHONY: clean fclean all re
