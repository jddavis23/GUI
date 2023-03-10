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
SRC2 = main.cpp
SRC2 += glad.c
SRC2 += win.cpp
SRC2 += Shader.cpp
LIB = lib/libglfw.3.3.dylib
INC = -I includes/GLFW/
INC += -I includes/glad/
INC += -I includes/

all: $(WINDOW) $(SHADERS)

$(WINDOW): $(SRC)
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC) $(LIB) -o $(WINDOW)

$(SHADERS): $(SRC2)
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC2) $(LIB) -o $(SHADERS)

fclean:
	rm $(WHOLE)

re: fclean all