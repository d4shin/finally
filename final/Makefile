# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amasrour <amasrour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 01:15:59 by amasrour          #+#    #+#              #
#    Updated: 2023/11/18 04:39:11 by amasrour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c utils.c utils2.c swap.c rotation.c push.c sort_helpers.c small_sort.c big_sort.c 
LIBFT = libft
HEADER = push_swap.h

all: $(NAME)

$(NAME):${SRC} ${HEADER}
	make -C $(LIBFT)
	$(CC) $(CFLAGS) ${SRC} -L$(LIBFT) -lft -o $(NAME)
	
clean:
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

bonus: all
	$(CC) $(CFLAGS) bonus.c -L$(LIBFT) -lft -o checker
	
re: fclean all
.PHONY: all clean fclean re
