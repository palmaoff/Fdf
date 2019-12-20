NAME = fdf

SRC =   main.c \
        draw_line.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror

MLX = ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INK	= -I ./miniLibX
MLX_LNK = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INKDIR	= ./includes/
OBJDIR	= ./obj/

all: $(NAME)

$(NAME): obj $(MLX_LIB) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) $(MLX_LNK) -o $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(FLAGS) $(MLX_INK) -I $(INKDIR) -o $@ -c $<

$(MLX_LIB):
	make -C $(MLX)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : all, re, clean, fclean