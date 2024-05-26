# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istili <istili@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 17:22:21 by istili            #+#    #+#              #
#    Updated: 2024/05/19 20:41:26 by istili           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

HEADER	=	so_long.h

FILE	=	main.c	handle_keys.c libc.c parsing.c parsing_2.c flood_fill.c textures.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		draw_map.c helpers.c check_line.c itoa.c\

OBJ		=	$(FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re