# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 03:07:19 by rfelipe-          #+#    #+#              #
#    Updated: 2022/09/07 20:55:15 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck -q ./miniRT

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

MLX_DIR = mlx_linux
MLX = mlx_linux/libmlx.a

SRC_DIR = src
SRC = $(SRC_DIR)/miniRT.c \
		$(SRC_DIR)/calc.c \
		$(SRC_DIR)/vectors/vector.c \
		$(SRC_DIR)/vectors/vector_multiplications.c \
		$(SRC_DIR)/rays/hit.c \
		$(SRC_DIR)/rays/ray.c \
		$(SRC_DIR)/utils/color.c \
		$(SRC_DIR)/utils/initiate.c \
		$(SRC_DIR)/matrix/matrix_determinant.c \
		$(SRC_DIR)/matrix/matrix_operations.c \
		$(SRC_DIR)/matrix/matrix.c

INCLUDE_DIR = includes
INCLUDE = $(INCLUDE_DIR)/miniRT.h

OBJ_DIR = objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME) -lm
	@echo "MiniRT compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/rays
	@mkdir -p $(OBJ_DIR)/vectors
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/matrix
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	@echo "Compiling project...\n"
	@make -C $(LIBFT_DIR)

$(MLX):
	@echo "Compiling minilibx...\n"
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting EVERYTHING...\n"
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "Project cleaned up!"

re: fclean all

valgrind: all
	@clear && $(VALGRIND)

v: valgrind

.PHONY:	all clean fclean re
