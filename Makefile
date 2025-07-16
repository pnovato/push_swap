NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT= $(LIBFT_DIR)/libft.a
SRC = src/main.c \
	src/parsing.c \
	src/utils.c \
	src/swap.c \
	src/push.c \
	src/rotate.c \
	src/reverse.c \
	src/sorting.c \
	src/radix.c
	
OBJ = $(SRC:.c=.o)

all: $(LIBFT)  $(NAME)

$(LIBFT):
	 $(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	 $(CC) $(CFLAGS) -I$(LIBFT_DIR) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

