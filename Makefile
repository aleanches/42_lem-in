# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 17:23:28 by pdiedra           #+#    #+#              #
#    Updated: 2019/09/07 13:38:59 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB 		= libft/libft.a

HEADER_NAME		= ft_lem_in.h
NAME 			= lem-in

INC_DIR 		= ./includes/
INC_LIB_FT 		= ./libft/includes/
SRC_DIR 		= ./src/
OBJ_DIR 		= ./obj/

SRC_NAME		= ants.c bfs.c connects.c free.c lem_in.c parse.c \
				parse_utils.c rooms.c routes.c routes_utils.c

HEADER 			= $(addprefix $(INC_DIR), $(HEADER_NAME))
SRC				= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ				= $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
GCC_LIBFT 		= -L ./libft -l ft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(NAME_LIB) $(HEADER)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
