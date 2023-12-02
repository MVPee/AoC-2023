# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 17:29:44 by mvpee             #+#    #+#              #
#    Updated: 2023/12/02 17:29:46 by mvpee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = day1

LIBFT = ../libft

SRCS = 	srcs/main.c

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