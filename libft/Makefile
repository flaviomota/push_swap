# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 16:23:30 by fmota             #+#    #+#              #
#    Updated: 2021/02/10 16:23:30 by fmota            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = $(shell find . -name "*.c" ! -name "*_bonus.c")

BONUS = $(shell find . -name "*_bonus.c")

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

all	: $(NAME)

$(NAME)	: $(OBJS) libft.h
		$(AR) $(NAME) $(OBJS)

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

bonus	: $(OBJS) $(BONUS_OBJS) libft.h
		$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)

clean	:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean	: clean
		rm -rf $(NAME)

re	:	fclean all



