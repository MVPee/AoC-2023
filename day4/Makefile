# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 18:52:13 by mvpee             #+#    #+#              #
#    Updated: 2023/12/04 19:00:10 by mvpee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = day3

LIBFT = ../libft

SRCS = 	srcs/main.c \
		srcs/ft_split_str.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -I$(LIBFT)

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	gcc $(OBJS) -L$(LIBFT) -lft -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re