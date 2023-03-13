#ifndef PROJ_HPP
#define PROJ_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "win.hpp"
#include "Shader.hpp"
#include "ProgShader.hpp"
#include <iostream>

static const char *vertexShaderSource = "#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

static const char *fragShaderSource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\0";


#endif