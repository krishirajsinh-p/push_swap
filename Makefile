# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 04:33:13 by kpuwar            #+#    #+#              #
#    Updated: 2023/05/31 21:46:17 by kpuwar           ###   ########.fr        #
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

$(BONUS): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT)/libft.a -I $(INCLUDESB) -o $(BONUS)

bonus: libft $(BONUS)

cleanb:
	$(RM) $(OBJSB)
	make -C $(LIBFT) clean

fcleanb: cleanb
	$(RM) $(BONUS)
	$(RM) $(LIBFT)/libft.a

reb: fcleanb bonus

.PHONY: all clean fclean re libft bonus cleanb fcleanb reb
