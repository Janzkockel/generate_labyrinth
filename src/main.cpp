#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>
#include <cstdlib>
#include <ctime>

void draw_rect(int32_t x, int32_t y, int32_t width, int32_t height, double r,
               double g, double b);

int32_t window_height = 700;
int32_t window_width = 1000;

const int32_t cols = 30;
const int32_t rows = 30;

bool pathExists(uint8_t start_col, uint8_t start_row)
{
    enum direction_enum
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    enum direction_enum direction = RIGHT;

    uint8_t current_pos[2];
    current_pos[0] = start_col;
    current_pos[1] = start_row;

    if (current_pos == ){

    }

    switch (direction)
    {
    case RIGHT:

        break;
    
    case LEFT:
    
        break;

    case DOWN:
        
        break;

    case UP:
        
        break;
    
    default:
        printf("direction undef");
        break;
    }

    return 0;
}

int main()
{
    // glfwInit();
    srand(time(NULL));
    uint8_t gameboard[cols][rows];

    const uint8_t start[2] = {0, 6}; // col, row
    const uint8_t target[2] = {29, 25};
    for (uint8_t cols_g = 0; cols_g <= cols - 1; cols_g++)
    { // _g = generate
        for (uint8_t rows_g = 0; rows_g <= rows - 1; rows_g++)
        {
            gameboard[cols_g][rows_g] = 1;
        }
    }

    gameboard[start[0]][start[1]] = 8;
    gameboard[target[0]][target[1]] = 9;

    while (!pathExists(start[0], start[1]))
    {
        uint8_t r_col = rand() % cols;
        uint8_t r_row = rand() % rows;

        if (r_col == start[0] && start[1] == 6)
        {
            gameboard[start[0]][start[1]] = 8;
        }
        else if (r_col == target[0] && r_row == target[1])
        {
            gameboard[target[0]][target[1]] = 8;
        }
        else{
            gameboard[r_col][r_row] = 0;
        }
    }

    // GLFWwindow *window = glfwCreateWindow(window_width, window_height, "generate Labyrinth", NULL, NULL);

    // while (!glfwWindowShouldClose(window))
    // {
    //     glfwGetWindowSize(window, &window_width, &window_height);
    //     glClear(GL_COLOR_BUFFER_BIT);
    //     glClearColor(0, 100, 255, 1);
    //     glfwPollEvents();

    //     draw_rect(100, 100, 200, 200, 255, 0, 0);

    //     glfwMakeContextCurrent(window);
    //     glfwSwapBuffers(window);
    // }

    // glfwTerminate();

    for (uint8_t cols_g = cols - 1; cols_g > 0; cols_g--)
    { // _g = generate
        for (uint8_t rows_g = rows - 1; rows_g > 0; rows_g--)
        { // _g = generate
            printf("%i ", gameboard[cols_g][rows_g]);
        }
        printf("\n");
    }
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