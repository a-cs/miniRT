# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 03:07:19 by rfelipe-          #+#    #+#              #
#    Updated: 2022/08/17 22:32:50 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc
FLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

MLX_DIR = mlx_linux
MLX = mlx_linux/libmlx.a

SRC_DIR = src
SRC = $(SRC_DIR)/miniRT.c \
		$(SRC_DIR)/vectors/vector.c \
		$(SRC_DIR)/vectors/vector_multiplications.c 

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
	@mkdir -p $(OBJ_DIR)/vectors
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

.PHONY:	all clean fclean re
