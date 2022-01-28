# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmozella <wmozella@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 20:28:23 by wmozella          #+#    #+#              #
#    Updated: 2022/01/28 23:04:03 by wmozella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			so_long

SRCS = 			check_map_a.c	check_map_b.c	ft_split.c	get_next_line.c 	main.c 	move_charecter.c \
				render.c 

#SRC_BONUS =		

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

LINKS = -lmlx -framework OpenGL -framework AppKit

HEADER	=	mandatory/so_long.h

HEADER_B	=	bonus/so_long.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAME_B):	$(OBJS_B)
			$(CC) $(SRCS_B) $(MLXFLAGS) $(CFLAGS) -o $(NAME_B)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus:		$(NAME_B)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re