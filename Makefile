WINDOW = window
SHADERS = shader
WHOLE = window
WHOLE += shader
CC = g++
FRAMEWORK = -framework CoreFoundation
ARGS = -Wall -Werror -Wextra -Wno-deprecated
FRAMEWORK += -framework OpenGL
SRC = window.cpp
SRC += glad.c
SRC2 = shaders.cpp
SRC2 += glad.c
LIB = lib/libglfw.3.3.dylib
INC = -I includes/GLFW/
INC += -I includes/glad/

all: $(WINDOW) $(SHADERS)

$(WINDOW):
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC) $(LIB) -o $(WINDOW)

$(SHADERS):
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC2) $(LIB) -o $(SHADERS)

fclean:
	rm $(WHOLE)

re: fclean all