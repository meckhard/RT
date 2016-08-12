# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehansman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/23 10:23:24 by ehansman          #+#    #+#              #
#    Updated: 2016/08/12 16:17:02 by cdebruyn         ###   ########.fr        #
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
	  $(SRC_PATH)key_hook.c				\
	  $(SRC_PATH)ft_atoi_shape.c		\
	  $(SRC_PATH)re_malloc.c			\
	  $(SRC_PATH)ask_commands.c			\
	  $(SRC_PATH)ask_commands2.c		\
	  $(SRC_PATH)ask_commands4.c		\
	  $(SRC_PATH)validate_commands.c	\
	  $(SRC_PATH)print_commands.c

OBJ = $(SRC:.c=.o)

BIN = $(INCL:.h=.h.gch)

BIN_2 = $(LIB_INCL:.h=.h.gch)

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
	@$(call colorecho, "Library has successfully compiled and object \
		files have been created and moved to src/")
	@clang $(C_FLAGS) $(OBJ) $(ATTACH) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./rt
	@clear
	@$(call colorecho, "RT has successfully compiled.\n")
	@rm -Rf $(OBJ) $(BIN) $(BIN_2)

clean:
	@/bin/rm -f $(OBJ) $(BIN) $(BIN_2)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME) $(LIB_A)
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) $(INCL)

q:
	@clang -I lbft/ -c $(SRC)
	@mv *.o src/
	@clang $(C_FLAGS) $(OBJ) $(ATTACH) $(LIB_INCL) $(LIB_A)
	@mv ./a.out ./rt
	@make clean

run:
	@./rt map

qr: q run

qme: 
	@rm -Rf author
	@whoami > author
