# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 18:03:01 by vsanta            #+#    #+#              #
#    Updated: 2019/08/19 17:50:13 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= libft.a

INC_DIR		= ./includes/
SRC_DIR 	= ./src/
OBJ_DIR		= ./obj/

HEADER_NAME	= libft.h get_next_line.h f_get_next_line.h

SRC_NAME	= ft_abs.c ft_lst_iter.c ft_putchar.c ft_strlen.c \
			ft_absl.c ft_lst_new.c ft_putchar_fd.c ft_strmap.c \
			ft_array_free.c ft_lst_pop_back.c ft_putendl.c ft_strmapi.c \
			ft_array_len.c ft_lst_pop_back_data.c ft_putendl_fd.c ft_strncat.c \
			ft_atoi.c ft_lst_pop_front.c ft_putnbr.c ft_strncmp.c \
			ft_atoi_base.c ft_lst_pop_front_data.c ft_putnbr_fd.c ft_strncpy.c \
			ft_atoull_base.c ft_lst_push_back.c ft_putstr.c ft_strnequ.c \
			ft_bzero.c ft_lst_push_back_data.c ft_putstr_fd.c ft_strnew.c \
			ft_digitcount.c ft_lst_push_front.c ft_skipspace.c ft_strnstr.c \
			ft_isalnum.c ft_lst_push_front_data.c ft_sqrt.c ft_strrchr.c \
			ft_isalpha.c ft_ltoa.c ft_strcat.c ft_strsplit.c \
			ft_isascii.c ft_memalloc.c ft_strchr.c ft_strstr.c \
			ft_isdigit.c ft_memccpy.c ft_strclr.c ft_strsub.c \
			ft_islower.c ft_memchr.c ft_strcmp.c ft_strtrim.c \
			ft_isprint.c ft_memcmp.c ft_strcpy.c ft_tolower.c \
			ft_isspace.c ft_memcpy.c ft_strdel.c ft_toupper.c \
			ft_isupper.c ft_memdel.c ft_strdup.c ft_ulltoa.c \
			ft_itoa.c ft_memmove.c ft_strequ.c ft_ulltoa_base.c \
			ft_itoa_base.c ft_memrcpy.c ft_striter.c ft_ultoa.c \
			ft_lltoa.c ft_memset.c ft_striteri.c ft_utoa.c \
			ft_lltoa_base.c ft_pow.c ft_strjoin.c ft_w_count.c \
			ft_lst_free.c ft_powl.c ft_strlcat.c get_next_line.c \
			ft_str_free.c ft_mtx_new.c ft_mtx_free.c ft_is_valid_int.c \
			ft_memdup.c \
			f_clear_fd_node.c ft_lstadd.c ft_lstcount.c ft_lstdelnode.c ft_lstclear.c \
			ft_lstiter.c ft_lstnew.c f_get_next_line.c f_clear_fd_node.c \
			ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_lstpushback.c \

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_DIR), $(SRC_NAME))
HEADER		= $(addprefix $(INC_DIR), $(HEADER_NAME))
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

FLAGS 		= -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) compiled"

$(OBJ_DIR):
	@mkdir -p obj
	@echo "object dir created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	gcc -c -I $(INC_DIR) $(FLAGS) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "all files removed"

re: fclean all
