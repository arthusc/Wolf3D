# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achambon <achambon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/04 15:40:27 by achambon          #+#    #+#              #
#    Updated: 2017/10/13 21:54:44 by achambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCPATH = ./srcs/

HEADER = ./includes/

SRCS = main.c \
		init.c \
		option.c \
		parse.c \
		error.c \
		algo.c \
		hooks.c \
		draw.c \


LIB = Libft/Libft.a

OBJ = $(SRCS:.c=.o)

FLAGS += -Wall -Wextra -Werror

FSRCS = $(addprefix $(SRCPATH), $(SRCS))

all : $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit $(LIB) $(FSRCS) -o $(NAME)

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
