# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achambon <achambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 15:40:27 by achambon          #+#    #+#              #
#    Updated: 2017/10/14 18:39:42 by achambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCPATH = ./srcs/

HEADER = ./includes/

SRCS = main.c \
		init.c \
		parse.c \
		algo.c \
		hooks.c \
		draw.c \


LIB = Libft/Libft.a

FLAGS += -Wall -Wextra -Werror #-g

FSRCS = $(addprefix $(SRCPATH), $(SRCS))

all : $(NAME)

$(NAME): $(FSRCS)
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit $(LIB) $(FSRCS) -o $(NAME)

clean :
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re