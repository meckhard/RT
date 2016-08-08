# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/23 10:23:24 by ehansman          #+#    #+#              #
#    Updated: 2016/08/08 11:45:22 by cdebruyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC = gcc

C_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./src/

INCL_PATH = ./includes/

INCL = $(INCL_PATH)rt.h			\
	   $(INCL_PATH)functions.h	\
	   $(INCL_PATH)structs.h	\

ATTACH = -lmlx -framework OpenGL -framework AppKit

LIB_INCL = -L. libft/libft.h

LIB_A = -lm libft/libft.a

SRC = $(SRC_PATH)main.c					\
	  $(SRC_PATH)sphere_raytrace2.c		\
	  $(SRC_PATH)raysphere2.c			\
	  $(SRC_PATH)ray_functions.c		\
	  $(SRC_PATH)set_var.c				\
	  $(SRC_PATH)key_hook.c

OBJ = $(SRC:.c=.o)

define colorecho
	@tput setaf 11
	@echo $1
	@tput sgr0
endef

all: $(NAME)

$(NAME): qme
	@$(call colorecho, "\nPreparing to compile raytracer...")
	@make -C libft/ re
	@clang $(C_FLAGS) -c $(SRC) -I $(INCL)
	@mv *.o src/
	@$(call colorecho, "Library hass successfully compiled and object \
		files have been created and moved to src/")
	@clang $(C_FLAGS) $(OBJ) $(ATTACH) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./RTv1
	@clear
	@$(call colorecho, "RT has successfully compiled.\n")
	@rm -Rf $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) $(INCL)

q:
	@clang -I lbft/ -c $(SRC)
	@clang $(C_FLAGS) -o $(NAME) $(OBJ) $(ATTACH)
	@make clean

run:
	@./rt map

qr: q run

qme: 
	@rm -Rf author
	@whoami > author
