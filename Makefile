NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft
LIBFT = libft/libft.a
SRC_DIR = src
OBJ_DIR = obj
RM = rm -f
SRCS = main.c parse.c parse_color.c parse_map.c parse_tex.c \
        parse_utils.c validate_map.c init.c texture.c render.c \
        raycast.c draw.c hooks.c loop.c move.c rotate.c utils.c
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
MLX_FLAGS = -lmlx -lXext -lX11 -lm
else
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/cub3d.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
