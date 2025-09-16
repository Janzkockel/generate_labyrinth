#include <stdio.h>
#include <stdbool.h>
#include "rightHandRule.h"

bool pathExists(int start[2], int target[2], int gameboard[80][80])
{
    enum direction_enum
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    enum direction_enum direction = RIGHT;

    int current_pos[2] = {start[0], start[1]};

    if (gameboard[start[0]][start[1]-1] == 1 && gameboard[target[0]][target[1] + 1] == 1 
        && gameboard[start[0] + 1][start[1]] == 1)
    {
        printf("[.]no way out of start yet\n");
        return 1;
    }

    while (current_pos[0] != target[0] && current_pos[1] != target[1])
    {
        while (gameboard[current_pos[0]][current_pos[1] - 1] == 0 ||
               gameboard[current_pos[0]][current_pos[1] - 1] == 8 ||
               gameboard[current_pos[0]][current_pos[1] - 1] == 9) // 1     // x(4)x    |
        {                                                                   // 1 p 3    |
            current_pos[1]--;                                               // x 2 x   \ /
        }                                                                   //          v    p looking down
        while (gameboard[current_pos[0] + 1][current_pos[1]] == 0 || 
               gameboard[current_pos[0] + 1][current_pos[1]] == 8 || 
               gameboard[current_pos[0] + 1][current_pos[1]] == 9) // 2
        {
            current_pos[0]++;
        }
        while (gameboard[current_pos[0]][current_pos[1] + 1] == 0 || 
               gameboard[current_pos[0]][current_pos[1] + 1] == 8 ||
               gameboard[current_pos[0]][current_pos[1] + 1] == 9) // 3
        {
            current_pos[1]++;
        }           
        while (gameboard[current_pos[0] - 1][current_pos[1]] == 0 ||
               gameboard[current_pos[0] - 1][current_pos[1]] == 8 ||
               gameboard[current_pos[0] - 1][current_pos[1]] == 9) // 4
        {
            current_pos[0]--;
        }

        if (current_pos[0] == start[0] && current_pos[1] == start[1])
        {
            // printf("[.] no way to target yet\n");
            return 1;
        }
    }
    return 0;
}