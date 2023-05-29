# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 04:33:13 by kpuwar            #+#    #+#              #
#    Updated: 2023/05/29 01:45:26 by kpuwar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

LIBFT	:= ./lib/libft

INCLUDES = $(wildcard src/include/*.h)
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

INCLUDESB = $(wildcard bonus/include/*.h)
SRCSB = $(wildcard bonus/*.c)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -I $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

bonus: libft $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT)/libft.a -I $(INCLUDESB) -o $(BONUS)

clean_bonus:
	$(RM) $(OBJSB)
	make -C $(LIBFT) clean

fclean_bonus: clean_bonus
	$(RM) $(BONUS)
	$(RM) $(LIBFT)/libft.a

re_bonus: fclean_bonus bonus

.PHONY: all clean fclean re bonus libft clean_bonus fclean_bonus
