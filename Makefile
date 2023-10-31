SRC = prueba.c	\
		error.c		\
		main.c 		\
		utils.c		\

OBJ = $(SRC:%.c=%.o)

# Directory structure
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Libraries and includes
LDFLAGS = -L$(LIBFT_DIR) -lft
INC = -I$(LIBFT_DIR)

# Executable name
NAME = prueba

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) $(INC)  $(LDFLAGS)  -o $@ $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
