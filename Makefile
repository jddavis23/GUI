NAME = proj
CC = c++
FRAMEWORK = -framework CoreFoundation
ARGS = -Wall -Werror -Wextra -Wno-deprecated
FRAMEWORK += -framework OpenGL
SRC = example.cpp
LIB = /Users/jdavis/.brew/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib

all: $(NAME)

$(NAME):
	$(CC) $(ARGS) $(FRAMEWORK) $(SRC) $(LIB) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all