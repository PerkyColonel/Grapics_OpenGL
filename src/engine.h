// System libs.
#include <iostream>
#include <vector>

// Include libs.
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

// Header includes.
// Using
using std::vector;

// Function prototypes.
void WindowResize(GLFWwindow *a_window, int a_width, int a_height);

// Classes.
class Engine
{
public:
    int Initialize();
    float gameSpeed = 0.1f;

private:
    int screenWidth = 800;
    int screenHeight = 600;

    const char *windowName = "Default Name";

    const char *vertexShaderSource;
    const char *fragmentShaderSource;
    unsigned int shaderProgram;
    unsigned int VBO, VAO, EBO;

    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    unsigned int indices[3] = {
        0, 1, 2};

    GLFWwindow *window;

    // Game loop.
    float lastFrameTime = 0.0f;
    glm::vec3 clearColor = glm::vec3(0.0f, 0.0f, 0.0f);

public:
    Engine(int a_width, int a_height, const char *a_windowName);

    void Update(float a_deltaTime);
    void Draw();

    void ProcessInput(GLFWwindow *a_window);

private:
    // OpenGL
    void SetupOpenGlRendering();
};