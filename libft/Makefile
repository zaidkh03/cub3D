NAME = libft.a

SRC = ft_strlen.c ft_strncmp.c ft_strdup.c ft_calloc.c ft_memset.c \
      ft_bzero.c ft_memcpy.c ft_substr.c ft_strjoin.c ft_split.c \
      ft_isdigit.c ft_atoi.c ft_strchr.c ft_putstr_fd.c \
      ft_putendl_fd.c get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
