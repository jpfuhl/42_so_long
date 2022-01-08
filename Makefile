# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 19:16:58 by jpfuhl            #+#    #+#              #
#    Updated: 2021/11/12 17:26:28 by jpfuhl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit
LIBFT_PATH = libft/
LIBFT =	make -C $(LIBFT_PATH)

SRCS = get_next_line/get_next_line.c \
get_next_line//get_next_line_utils.c \
movement/check_player_position.c \
movement/move_player.c \
movement/set_player_movement_tiles.c \
movement/trigger_player_movement.c \
parsing/check_if_ber.c \
parsing/initialise_structs.c \
parsing/parse_map.c \
parsing/place_tiles.c \
parsing/set_tiles.c \
parsing/validate_map.c \
main.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L. ./minilibx/libmlx.a $(MLX) -lz libft/libft.a -o $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f get_next_line/*.o
	rm -f movement/*.o
	rm -f parsing/*.o
	rm -f main.o

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f *~
	rm -f $(NAME)

re: fclean all
