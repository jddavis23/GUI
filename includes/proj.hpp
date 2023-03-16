#ifndef PROJ_HPP
#define PROJ_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "win.hpp"
#include "Shader.hpp"
#include "ProgShader.hpp"
#include "ReadComp.hpp"
#include "LoadTex.hpp"

static const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n" // the position variable has attribute position 0
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n" // specify a color output to the fragment shader
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos, 1.0);\n" // see how we directly give a vec3 to vec4's constructor
"    ourColor = aColor;\n" // set the output variable to a dark-red color
"}\0";

static const char *fragShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n" 
"in vec3 ourColor;\n" // the input variable from the vertex shader (same name and same type)  
"void main()\n"
"{\n"
"    FragColor = vec4(ourColor, 1.0);\n"
"}\0";



// static const char *vertexShaderSource = "#version 330 core\n"
// 	"layout (location = 0) in vec3 aPos;\n"
// 	"void main()\n"
// 	"{\n"
// 	"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
// 	"}\0";

// static const char *fragShaderSource = "#version 330 core\n"
// 	"out vec4 FragColor;\n"
// 	"void main()\n"
// 	"{\n"
// 	"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
// 	"}\0";


#endif