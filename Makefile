NAME = proj
CC = g++
FRAMEWORK = -framework CoreFoundation
ARGS = -Wall -Werror -Wextra -Wno-deprecated
FRAMEWORK += -framework OpenGL
SRC = example.cpp
SRC += glad.c
LIB = lib/libglfw.3.3.dylib
INC = -I includes/GLFW/
INC += -I includes/glad/

all: $(NAME)

$(NAME):
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC) $(LIB) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all