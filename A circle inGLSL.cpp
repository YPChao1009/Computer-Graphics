/*
 *A circle inGLSL.cpp
 * Author:Yun Pei Chao 
 */
#include <glad/glad.h> 
#include <GLFW/glfw3.h> 
#include "./shader.c" 
#include <iostream> 
void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void processInput(GLFWwindow *window); 
// settings 
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 700; 
int main() 
{ 
// glfw: initialize and configure 
// ------------------------------ 
glfwInit(); 
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
#ifdef __APPLE__ 
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to 
fix compilation on OS X 
#endif 
// glfw window 
creation 
// 
-------------------- 
GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, 
NULL); 
glfwMakeContextCurrent(window); 
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
// glad: load all OpenGL function pointers 
// --------------------------------------- 
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
{ 
std::cout << "Failed to initialize GLAD" << std::endl; 
return -1; 
} 
// build and compile our shader program 
// ------------------------------------ 
Shader ourShader("./3.3.shader.vert", "3.3.shader.frag"); // you can name your shader 
files however you like 
// set up 
vertex data (and buffer(s)) and configure vertex attributes 
// 
------------------------------------------------------------------ 
float vertices[] = { 
// positions // colors 
0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // 右上 
0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 右下 
-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // 左上 
0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // 右下 
-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, //左下 
-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // 左上 
}; 
unsigned int VBO, VAO; 
glGenVertexArrays(1, &VAO); 
glGenBuffers(1, &VBO); 
// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then 
configure vertex attributes(s). 
glBindVertexArray(VAO); 
glBindBuffer(GL_ARRAY_BUFFER, VBO); 
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
// position attribute 
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); 
glEnableVertexAttribArray(0); 
// color attribute 
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * 
sizeof(float))); 
glEnableVertexAttribArray(1); 
// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this 
VAO, but this rarely happens. Modifying other 
// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs 
(nor VBOs) when it's not directly necessary. 
// glBindVertexArray(0); 
// render loop 
// ----------- 
while (!glfwWindowShouldClose(window)) 
{ 
// input 
// ----- 
processInput(window); 
// render 
// ------ 
glClearColor(0.2f, 0.3f, 0.3f, 1.0f); 
glClear(GL_COLOR_BUFFER_BIT); 
// render the triangle 
ourShader.use(); 
glBindVertexArray(VAO); 
glDrawArrays(GL_TRIANGLES, 0, 6); 
// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.) 
// 
------------------------------------------------------------------------------- 
glfwSwapBuffers(window); 
glfwPollEvents(); 
} 
// optional: de-allocate all resources once they've outlived their purpose: 
// ------------------------------------------------------------------------ 
glDeleteVertexArrays(1, &VAO); 
glDeleteBuffers(1, &VBO); 
// glfw: terminate, clearing all previously allocated GLFW resources. 
// ------------------------------------------------------------------ 
glfwTerminate(); 
return 0; 
} 
// process all input: query GLFW whether relevant keys are pressed/released this frame and 
react accordingly 
// 
-------------------------------------------------------------------------------------- 
------------------ 
void processInput(GLFWwindow *window) 
{ 
if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
glfwSetWindowShouldClose(window, true); 
} 
// glfw: whenever the window size changed (by OS or user resize) this callback function 
executes 
// 
-------------------------------------------------------------------------------------- 
------ 
void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{ 
// make sure the viewport matches the new window dimensions; note that width and 
// height will be significantly larger than specified on retina displays. 
glViewport(0, 0, width, height); 
} 
SHADER.C 
#ifndef SHADER_H 
#define SHADER_H 
#include <glad/glad.h> 
#include <glm/glm.hpp> 
#include <string> 
#include <fstream> 
#include <sstream> 
#include <iostream> 
class Shader 
{ 
public: 
unsigned int ID; 
// constructor generates the shader on the fly 
// ------------------------------------------------------------------------ 
Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = 
nullptr) 
{ 
// 1. retrieve the vertex/fragment source code from filePath 
std::string vertexCode; 
std::string fragmentCode; 
std::string geometryCode; 
std::ifstream vShaderFile; 
std::ifstream fShaderFile; 
std::ifstream gShaderFile; 
// ensure ifstream objects can throw exceptions: 
vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); 
fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); 
gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit); 
try 
{ 
// open files 
vShaderFile.open(vertexPath); 
fShaderFile.open(fragmentPath); 
std::stringstream vShaderStream, fShaderStream; 
// read file's buffer contents into streams 
vShaderStream << vShaderFile.rdbuf(); 
fShaderStream << fShaderFile.rdbuf(); 
// close file handlers 
vShaderFile.close(); 
fShaderFile.close(); 
// convert stream into string 
vertexCode = vShaderStream.str(); 
fragmentCode = fShaderStream.str(); 
// if geometry shader path is present, also load a geometry shader 
if (geometryPath != nullptr) 
{ 
gShaderFile.open(geometryPath); 
std::stringstream gShaderStream; 
gShaderStream << gShaderFile.rdbuf(); 
gShaderFile.close(); 
geometryCode = gShaderStream.str(); 
} 
} 
catch (std::ifstream::failure e) 
{ 
std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl; 
} 
const char* vShaderCode = vertexCode.c_str(); 
const char * fShaderCode = fragmentCode.c_str(); 
// 2. compile shaders 
unsigned int vertex, fragment; 
// vertex shader 
vertex = glCreateShader(GL_VERTEX_SHADER); 
glShaderSource(vertex, 1, &vShaderCode, NULL); 
glCompileShader(vertex); 
checkCompileErrors(vertex, "VERTEX"); 
// fragment Shader 
fragment = glCreateShader(GL_FRAGMENT_SHADER); 
glShaderSource(fragment, 1, &fShaderCode, NULL); 
glCompileShader(fragment); 
checkCompileErrors(fragment, "FRAGMENT"); 
// if geometry shader is given, compile geometry shader 
unsigned int geometry; 
if (geometryPath != nullptr) 
{ 
const char * gShaderCode = geometryCode.c_str(); 
geometry = glCreateShader(GL_GEOMETRY_SHADER); 
glShaderSource(geometry, 1, &gShaderCode, NULL); 
glCompileShader(geometry); 
checkCompileErrors(geometry, "GEOMETRY"); 
} 
// shader Program 
ID = glCreateProgram(); 
glAttachShader(ID, vertex); 
glAttachShader(ID, fragment); 
if (geometryPath != nullptr) 
glAttachShader(ID, geometry); 
glLinkProgram(ID); 
checkCompileErrors(ID, "PROGRAM"); 
// delete the shaders as they're linked into our program now and no longer necessery 
glDeleteShader(vertex); 
glDeleteShader(fragment); 
if (geometryPath != nullptr) 
glDeleteShader(geometry); 
} 
// activate the shader 
// ------------------------------------------------------------------------ 
void use() 
{ 
glUseProgram(ID); 
} 
// utility uniform functions 
// ------------------------------------------------------------------------ 
void setBool(const std::string &name, bool value) const 
{ 
glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
} 
// ---------------------------------------------------------
--------------- 
void setInt(const std::string &name, int value) const 
{ 
glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
} 
// ------------------------------------------------------------------------ 
void setFloat(const std::string &name, float value) const 
{ 
glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 
// ------------------------------------------------------------------------ 
void setVec2(const std::string &name, const glm::vec2 &value) const 
{ 
glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
} 
void setVec2(const std::string &name, float x, float y) const 
{ 
glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
} 
// ------------------------------------------------------------------------ 
void setVec3(const std::string &name, const glm::vec3 &value) const 
{ 
glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
} 
void setVec3(const std::string &name, float x, float y, float z) const 
{ 
glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
} 
// ------------------------------------------------------------------------ 
void setVec4(const std::string &name, const glm::vec4 &value) const 
{ 
glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
} 
void setVec4(const std::string &name, float x, float y, float z, float w) 
{ 
glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
} 
// ------------------------------------------------------------------------ 
void setMat2(const std::string &name, const glm::mat2 &mat) const 
{ 
glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, 
&mat[0][0]); 
} 
// ------------------------------------------------------------------------ 
void setMat3(const std::string &name, const glm::mat3 &mat) const 
{ 
glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, 
&mat[0][0]); 
} 
// ------------------------------------------------------------------------ 
void setMat4(const std::string &name, const glm::mat4 &mat) const 
{ 
glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 
1, GL_FALSE, 
&mat[0][0]); 
} 
private: 
// utility function for checking shader compilation/linking errors. 
// ------------------------------------------------------------------------ 
void checkCompileErrors(GLuint shader, std::string type) 
{ 
GLint success; 
GLchar infoLog[1024]; 
if (type != "PROGRAM") 
{ 
glGetShaderiv(shader, GL_COMPILE_STATUS, &success); 
if (!success) 
{ 
glGetShaderInfoLog(shader, 1024, NULL, infoLog); 
std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << 
"\n" << infoLog << "\n -- --------------------------------------------------- -- " << 
std::endl; 
} 
} 
else 
{ 
glGetProgramiv(shader, GL_LINK_STATUS, &success); 
if (!success) 
{ 
glGetProgramInfoLog(shader, 1024, NULL, infoLog); 
std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" 
<< infoLog << "\n -- --------------------------------------------------- -- " << std::endl; 
} 
} 
} 
}; 
#endif 
