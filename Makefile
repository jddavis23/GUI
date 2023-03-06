NAME=proj




all: $(NAME)

$(NAME):
	gcc -framework CoreFoundation -framework OpenGL example.cpp /Users/jdavis/.brew/Cellar/glfw/3.3.8/lib/libglfw.3.3.dylib -o $(NAME)