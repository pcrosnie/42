# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 14:30:37 by rdieulan          #+#    #+#              #
#    Updated: 2015/12/17 15:42:04 by rdieulan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_get_tetriminos.c\
		ft_check_validity.c\
		ft_get_coord.c\
		ft_search_range.c\
		ft_tree.c\
		libft.a\

OBJS = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
