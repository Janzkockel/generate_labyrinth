#include <GLFW/glfw3.h>
#include <stdio.h>

void draw_rect(int32_t x, int32_t y, int32_t width, int32_t height, double r,
               double g, double b);

int32_t window_height = 700;
int32_t window_width = 1000;

const int32_t cols = 30;
const int32_t rows = 30;

int main()
{
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(window_width, window_height, "generate Labyrinth", NULL, NULL);

#include <stdbool.h>

    bool gameboard[cols][rows];
    


    while (!glfwWindowShouldClose(window))
    {
        glfwGetWindowSize(window, &window_width, &window_height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 100, 255, 1);
        glfwPollEvents();

        draw_rect(100, 100, 200, 200, 255, 0, 0);

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void draw_rect(int32_t x, int32_t y, int32_t width, int32_t height, double r,
               double g, double b)
{
    double readfinal = 1.0 / 255 * r;
    double greenfinal = 1.0 / 255 * g;
    double bluefinal = 1.0 / 255 * b;

    glColor3f(readfinal, greenfinal, bluefinal);

    double xf = 2.0 / window_width * x - 1.0;
    double yf = 2.0 / window_height * y - 1.0;

    double wf = 2.0 / window_width * width + xf;
    double hf = 2.0 / window_height * height + yf;

    glRectf(xf, yf, wf, hf);
}