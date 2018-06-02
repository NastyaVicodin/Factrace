# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 16:58:58 by iseletsk          #+#    #+#              #
#    Updated: 2018/04/17 09:40:07 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = factrace

SRC_DIR :=		./sources/
OBJ_DIR :=		./objects/
INC_DIR :=		./includes/
LIB_DIR :=		./libraries/

SRC :=		main.c get_next_line.c ft_wizard.c ft_strnew.c ft_strncpy.c ft_strlen.c ft_strjoin.c ft_count_c.c ft_putstr.c \
			ft_strchr.c ft_strdup.c ft_memalloc.c ft_strcat.c ft_strcpy.c ft_memset.c ft_strdel.c ft_memdel.c decomp_num.c

OBJ =		$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC_FLAGS :=		-Wall -Wextra -Werror

HEADER_FLAGS :=	-I $(INC_DIR)

CC :=		gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS)  $(OBJ) libgmp.a -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
