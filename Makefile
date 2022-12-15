# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 11:57:23 by fle-tolg          #+#    #+#              #
#    Updated: 2022/11/25 11:25:47 by fle-tolg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
END = \033[0m

NAME = so_long

CFLAGS = -Wextra -Wall -Werror

MINILIBXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MINILIBXDIR = ./mlx_linux/ --no-print-directory

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft/ --no-print-directory

CC = clang -g

RM = rm -f

OBJ = $(SRC:.c=.o)

SRC = 	main.c\
		sources/read_map.c\
		sources/verif_map.c\
		sources/initialize_map.c\
		sources/move.c\
		sources/update.c\
		sources/add_on_map.c\
		sources/add_on_map2.c\
		sources/verif_feasibility.c\
		sources/verif_sword.c

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

$(NAME) : ${OBJ}
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBXDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXFLAGS) -o $(NAME)
	@echo "${GREEN}$(NAME) compilated with success"

all : $(NAME)

norme :
	norminette libft
	norminette sources
	norminette includes
	norminette main.c

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBXDIR) clean
	@$(RM) $(OBJ)
	@echo "$(NAME) clean"

fclean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBXDIR) clean
	@$(RM) $(OBJ) $(NAME)
	@echo "${RED}$(NAME) fclean"

re :	fclean all

.PHONY :
	all clean fclean re
