#include "rightHandRule.h"
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int start[2] = {0, 6};    // col, row
    int target[2] = {79, 79}; // col, row
    int gameboard[80][80];    // 1 = wall, 0 = way, 8 = start, 9 = target

    for (int cols = 0; cols < 80; cols++)
    {
        for (int rows = 0; rows < 80; rows++)
        {
            gameboard[cols][rows] = 1;
        }
    }

    for (int cols = 0; cols < 79; cols++)
    {
        gameboard[cols][6] = 0;
    }
    for (int rows = 6; rows < 80; rows++)
    {
        gameboard[79][rows] = 0;
    }

    gameboard[start[0]][start[1]] = 8;   // 8 = start
    gameboard[target[0]][target[1]] = 9; // 9 = target
    
    // gameboard[43][6] = 1; // block the way to test no path exists
    
    for (int cols = 0; cols < 80; cols++)
    {
        for (int rows = 0; rows < 80; rows++)
        {
            if (gameboard[cols][rows] == 1)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }

    if (pathExists(start, target, gameboard))
    {
        printf("no path exists\n");
    }
    else
    {
        printf("path exists\n");
    }


    return 0;
}
