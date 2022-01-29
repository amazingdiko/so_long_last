# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#              #
#    Updated: 2022/01/29 22:38:37 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = mandatory/check_map_a.c\
	mandatory/check_map_b.c\
	mandatory/ft_split.c\
	mandatory/main.c\
	mandatory/get_next_line.c\
	mandatory/move_charecter.c\
	mandatory/render.c\

SRC_BONUS = bonus/print_moves_bonus.c\
	bonus/get_next_line_bonus.c\
	bonus/render_bonus.c\
	bonus/move_charecter_bonus.c\
	bonus/check_map_a_bonus.c\
	bonus/ft_split_bonus.c\
	bonus/check_map_b_bonus.c\
	bonus/main_bonus.c\

HDRS = mandatory/so_long.h

HDRS_BONUS = bonus/so_long_bonus.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		make -C mlx
		$(CC) $(CFLAGS) $(MLX_FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		make -C mlx
		$(CC) $(CFLAGS) $(MLX_FLAGS) -I mlx $(OBJ_BONUS) -I. -o $(NAME)

clean:
		make clean -C mlx
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean