#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#include <ctime>
#include "rightHandRule.h"

void draw_rect(int x, int y, int width, int height, double r,
               double g, double b);

int window_height = 700;
int window_width = 1000;

const int cols = 80;
const int rows = 80;

int start[2] = {0, 6};    // col, row
int target[2] = {29, 25}; // col, row

int main()
{
    srand(time(NULL));
    int gameboard[cols][rows]; // 1 = wall, 0 = way, 8 = start, 9 = target

    for (int cols_g = 0; cols_g <= cols - 1; cols_g++)
    { // _g = generate
        for (int rows_g = 0; rows_g <= rows - 1; rows_g++)
        {
            gameboard[cols_g][rows_g] = 1;
        }
    }

    gameboard[start[0]][start[1]] = 8;   // 8 = start
    gameboard[target[0]][target[1]] = 9; // 9 = target

    while (pathExists(start, target, gameboard))
    {
        // for (int cols_p = cols - 1; cols_p > 0; cols_p--)
        // { // _p = print
        //     for (int rows_p = rows - 1; rows_p > 0; rows_p--)
        //     { // _p = print
        //         if (gameboard[cols_p][rows_p] == 1)
        //             printf("# ");
        //         else if (gameboard[cols_p][rows_p] == 8)
        //             printf("S ");
        //         else if (gameboard[cols_p][rows_p] == 9)
        //             printf("T ");
        //         else
        //             printf(". ");
        //     }
        //     printf("\n");
        // }

        int r_col = rand() % cols;
        int r_row = rand() % rows;

        if (r_col == start[0] && r_row == start[1])
        {
            gameboard[start[0]][start[1]] = 8;
            printf("[+] 8 happend");
        }
        else if (r_col == target[0] && r_row == target[1])
        {
            gameboard[target[0]][target[1]] = 9;
            printf("[+] 9 happend");

        }
        else
        {
            gameboard[r_col][r_row] = 0;
        }
    }

    printf("path exists\n");

    glfwInit();
    GLFWwindow *window = glfwCreateWindow(window_width, window_height, "generate Labyrinth", NULL, NULL);

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

void draw_rect(int x, int y, int width, int height, double r,
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