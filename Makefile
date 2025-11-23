# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imelero- <imelero-@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 13:34:43 by imelero-          #+#    #+#              #
#    Updated: 2025/11/21 20:26:32 by nacho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush

FLAG = -Wall -Wextra -Werror

HEADER = Makefile rush.h

SRC = main.c \
		parse.c \
		rush_utils.c \
		ft_split.c \
		alg.c \
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cc $(FLAG) $(OBJ) -o $(NAME)
	@echo "$(NAME) created" 

%.o: %.c $(HEADER)
	@cc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ removed"

fclean: clean
	@rm -f $(OBJ) $(NAME) rush.a
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re
