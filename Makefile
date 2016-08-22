
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

SRC =	$(SRC_PATH)main.c					\
		$(SRC_PATH)read_map.c				\
		$(SRC_PATH)get_objects.c			\
		$(SRC_PATH)reverse_lists.c			\
		$(SRC_PATH)object_lists.c			\
		$(SRC_PATH)print_map.c				\
		$(SRC_PATH)free_map.c				\

OBJ = $(SRC:.c=.o)

BIN = $(INCL:.h=.h.gch)

BIN_2 = $(LIB_INCL:.h=.h.gch)

define colorecho
	@tput setaf 11
	@echo $1
	@tput sgr0
endef

all: $(NAME)

$(NAME):
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
	@rm -rf $(OBJ)

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
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
