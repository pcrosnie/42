# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 14:30:37 by rdieulan          #+#    #+#              #
#    Updated: 2015/12/16 14:48:19 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	main.c\
		ft_get_tetriminos.c\
		ft_check_validity.c\
		ft_get_coord\
		ft_search_range\
		ft_tree.c\

OBJS = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
