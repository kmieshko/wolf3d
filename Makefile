# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 17:57:43 by kmieshko          #+#    #+#              #
#    Updated: 2018/12/17 17:57:45 by kmieshko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

PATH_SRCS = ./srcs

SRCS = $(PATH_SRCS)/main.c \
		$(PATH_SRCS)/error.c \
		$(PATH_SRCS)/parse_map.c \
		$(PATH_SRCS)/ft_pixel_put.c \
		$(PATH_SRCS)/find_person_position.c \
		$(PATH_SRCS)/ft_clamp_with_param.c \
		$(PATH_SRCS)/get_color.c \
		$(PATH_SRCS)/get_textures.c \
		$(PATH_SRCS)/manage.c \
		$(PATH_SRCS)/calcs.c \
		$(PATH_SRCS)/init.c \
		$(PATH_SRCS)/wall_color.c \
		$(PATH_SRCS)/get_music.c \
		$(PATH_SRCS)/draw.c \
		$(PATH_SRCS)/ceiling_floor.c

OBJ = $(SRCS:.c=.o)

LIB = ./libft/libft.a

INCL = -I ./include/

INCL_FRM = -I ./frm/SDL2.framework/Headers/ \
		-I ./frm/SDL2_image.framework/Headers/ \
		-I ./frm/SDL2_ttf.framework/Headers/

FRMX = -F ./frm \
		-framework SDL2 \
		-framework SDL2_image \
		-framework SDL2_mixer \
		-framework SDL2_ttf \

FRMP = -rpath @loader_path/frm/

COMPILE = gcc -c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FRMP) $(FRMX) $(OBJ) $(FLAGS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(COMPILE) -o $@ $< $(FLAGS) $(INCL) $(INCL_FRM)
	
clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft
