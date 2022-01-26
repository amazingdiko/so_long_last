# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#              #
#    Updated: 2022/01/22 21:24:11 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			so_long

HEAD =			so_long.h

LIBDIR = 		./libft/

LIBFT = 		libft.a

#HEAD_BONUS =	so_long_bonus.h

SRC = 			so_long.c

#SRC_BONUS =		

OBJ =			$(SRC:%.c=%.o)

OBJ_BONUS =		$(SRC_BONUS:%.c=%.o)

D =				$(SRC:%.c=%.d)

D_BONUS =		$(SRC_BONUS:%.c=%.d)

CFLAGS = 		-Wall -Werror -Wextra -MD -I./libft/

CC = 			gcc

RM = 			rm -f

all : 			libmake $(NAME)

$(NAME) : 		$(OBJ)
				@cp $(LIBDIR)$(LIBFT) .
				$(CC) $(CFLAGS) $(OBJ) libft.a -lmlx -framework OpenGL -framework AppKit -o $@

libmake :
				@make -C $(LIBDIR)

%.o : 			%.c
				$(CC) $(CFLAGS) -Imlx -I $(HEAD) -c $< -o $@

include 		$(wildcard $(D) $(D_BONUS))

bonus:
				@make OBJ="$(OBJ_BONUS)" HEAD="$(HEAD_BONUS)" all

clean:
				@make clean -C $(LIBDIR)
				@$(RM) $(OBJ) $(D) $(D_BONUS) $(OBJ_BONUS)

fclean: 		clean
				@$(RM) $(NAME) $(LIBFT)

re: 			fclean all

.PHONY: 		all clean fclean re bonus