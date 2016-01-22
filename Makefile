#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: espiroux <espiroux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/11 12:43:05 by espiroux          #+#    #+#              #
#    Updated: 2013/12/17 12:29:57 by espiroux         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

export CC= gcc
export CFLAGS= -Werror -Wall -Wextra -ansi -pedantic

MLX_FLAGS= -lmlx -lXext -lX11
NAME=wolf3D
LIBFT_DIR=libft/
LIBMLX_DIR=/usr/X11/lib
INC_DIR=includes/
SRC_DIR=src/

FT_C=	$(SRC_DIR)$(NAME).c $(SRC_DIR)hook.c $(SRC_DIR)draw.c $(SRC_DIR)draw_ground.c \
		$(SRC_DIR)draw_sprite.c $(SRC_DIR)readfile.c $(SRC_DIR)get_next_line.c \
		$(SRC_DIR)init_game.c $(SRC_DIR)move.c $(SRC_DIR)helper.c $(SRC_DIR)draw_weapon.c\
		$(SRC_DIR)draw_wolf.c $(SRC_DIR)shoot_animation.c $(SRC_DIR)texture.c \
		$(SRC_DIR)hit_sprite.c $(SRC_DIR)init_sprite.c $(SRC_DIR)put_coor_img.c\
		$(SRC_DIR)get_img_color.c $(SRC_DIR)draw_sky.c $(SRC_DIR)draw_wall.c\
		$(SRC_DIR)calc_sprite.c $(SRC_DIR)calc_const_sprite.c $(SRC_DIR)calc_transf.c\
		$(SRC_DIR)sprite_order.c $(SRC_DIR)draw_y_sprite.c $(SRC_DIR)ft_double_swap.c\
		$(SRC_DIR)ft_int_swap.c $(SRC_DIR)draw_limiter.c $(SRC_DIR)get_timeframe.c\

FT_O=$(FT_C:.c=.o)

.PHONY: clean fclean

all: $(NAME)

$(NAME): a
		@echo CREATE $(NAME)
		@gcc $(CFLAGS) -L$(LIBMLX_DIR) -I /usr/X11/include/ -I $(INC_DIR) $(MLX_FLAGS) $(FT_C) ./libft/libft.a -o $(NAME) -g

a:
		@(cd $(LIBFT_DIR) && $(MAKE))

clean:
		@(cd $(LIBFT_DIR) && $(MAKE) $@)
		@/bin/rm -rf $(NAME).dSYM


fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
