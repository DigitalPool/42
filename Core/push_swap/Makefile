# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 18:34:58 by ashobajo          #+#    #+#              #
#    Updated: 2024/08/19 20:53:13 by ashobajo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRCS =	push_swap/ft_add_args_to_stack.c \
			push_swap/ft_check_args.c \
			push_swap/ft_check_duplicate.c \
			push_swap/ft_check_if_sorted.c \
			push_swap/ft_create_new_node.c \
			push_swap/ft_free_stack.c \
			push_swap/ft_get_lst_size.c \
			push_swap/ft_get_stack.c\
			push_swap/ft_print_error.c \
			push_swap/ft_sort_stack.c \
			push_swap/ft_stack_utils.c \
			push_swap/ft_parse_args_quoted\
			push_swap/push_operations.c \
			push_swap/push_swap.c \
			push_swap/rev_rotate_operations.c \
			push_swap/rotate_operations.c \
			push_swap/swap_operations.c\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(OBJS): | $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean :
	$(RM) $(OBJS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY: all clean fclean re
