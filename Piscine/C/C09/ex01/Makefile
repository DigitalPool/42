# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 17:48:43 by ashobajo          #+#    #+#              #
#    Updated: 2024/03/20 18:28:49 by ashobajo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS_DIR = srcs
INCS_DIR = includes
SRCS_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS_DIR = $(SRCS_DIR)
OBJS_FILES = $(SRCS_FILES:.c=.o)
SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJS_FILES))
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $(NAME)"
	@$(AR) $(ARFLAGS) $@ $^

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects"
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
