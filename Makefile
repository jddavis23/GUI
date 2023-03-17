WINDOW = window
SHADERS = shader
TEXTURE = texture
WHOLE = window
WHOLE += shader
WHOLE += texture
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
SRC2 += ProgShader.cpp
SRC2 += ReadComp.cpp

SRC3 = text_main.cpp
SRC3 += glad.c
SRC3 += win.cpp
SRC3 += Shader.cpp
SRC3 += ProgShader.cpp
SRC3 += ReadComp.cpp
SRC3 += stb.cpp
SRC3 += LoadTex.cpp
SRC3 += Buffer.cpp

LIB = lib/libglfw.3.3.dylib
INC = -I includes/GLFW/
INC += -I includes/glad/
INC += -I includes/

all: $(WINDOW) $(SHADERS)

$(WINDOW): $(SRC)
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC) $(LIB) -o $(WINDOW)

$(SHADERS): $(SRC2)
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC2) $(LIB) -o $(SHADERS)

$(TEXTURE): $(SRC3)
	$(CC) $(ARGS) $(INC) $(FRAMEWORK) $(SRC3) $(LIB) -o $(TEXTURE)

fclean:
	rm $(WHOLE)

re: fclean all