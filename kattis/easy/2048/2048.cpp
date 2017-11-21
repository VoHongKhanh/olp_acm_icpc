#include <iostream>

using namespace std;

/*
2048

2048 is a single-player puzzle game created by Gabriele Cirulli. It is played on a 4x4 grid that contains integers >=2
that are powers of 2. The player can use a keyboard arrow key (left/up/right/down) to move all the tiles simultaneously.
Tiles slide as far as possible in the chosen direction until they are stopped by either another tile or the edge of the grid.
If two tiles of the same number collide while moving, they will merge into a tile with the total value of the two tiles
that collided. The resulting tile cannot merge with another tile again in the same move. Please observe this merging behavior
carefully in all Sample Inputs and Outputs.

Input
The input is always a valid game state of a 2048 puzzle. The first four lines of input, that each contains four integers,
describe the 16 integers in the 4x4 grid of 2048 puzzle. The j-th integer in the i-th line denotes the content of the cell
located at the ii-th row and the j-th cell. For this problem, all integers in the input will be either
{0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}. Integer 0 means an empty cell.

The fifth line of input contains an integer 0, 1, 2, or 3 that denotes a left, up, right, or down move executed by the player,
respectively.

Output
Output four lines with four integers each. Two integers in a line must be separated by a single space. This describes
the new state of the 4x4 grid of 2048 puzzle. Again, integer 0 means an empty cell. Note that in this problem, you can
ignore the part from the 2048 puzzle where it introduces a new random tile with a value of either 2 or 4 in an empty spot of
the board at the start of a new turn.

Sample Input 1	Sample Output 1
2 0 0 2         4 0 0 0
4 16 8 2        4 16 8 2
2 64 32 4       2 64 32 4
1024 1024 64 0  2048 64 0 0
0

Sample Input 2	Sample Output 2
2 0 0 2         2 16 8 4
4 16 8 2        4 64 32 4
2 64 32 4       2 1024 64 0
1024 1024 64 0  1024 0 0 0
1

Sample Input 3	Sample Output 3
2 0 0 2         0 0 0 4
4 16 8 2        4 16 8 2
2 64 32 4       2 64 32 4
1024 1024 64 0  0 0 2048 64
2

Sample Input 4	Sample Output 4
2 0 0 2         2 0 0 0
4 16 8 2        4 16 8 0
2 64 32 4       2 64 32 4
1024 1024 64 0  1024 1024 64 4
3

Sample Input 5	Sample Output 5
2 2 4 8         4 4 8 0
4 0 4 4         8 4 0 0
16 16 16 16     32 32 0 0
32 16 16 32     32 32 32 0
0

Sample Input 6	Sample Output 6
2 2 4 8         0 4 4 8
4 0 4 4         0 0 4 8
16 16 16 16     0 0 32 32
32 16 16 32     0 32 32 32
2
*/

int a[4][4], i, j, direction;

void goLeft(int d, int i) {
    for (int j=i+1; j<=3; j++) {
        a[d][j-1] = a[d][j];
    }
    a[d][3] = 0;
}
void clearLeft(int d) {
    for (int i=3; i>=0; i--) {
        if (a[d][i] == 0) {
            goLeft(d, i);
        }
    }
}
void moveLeft(int d) {
    clearLeft(d);
    if (a[d][0]==a[d][1]) {
        a[d][0]*= 2;
        a[d][1] = a[d][2];
        a[d][2] = a[d][3];
        a[d][3] = 0;
        if (a[d][1]==a[d][2]) {
            a[d][1]*= 2;
            a[d][2] = 0;
        }
    } else if(a[d][1]==a[d][2]) {
        a[d][1]*= 2;
        a[d][2] = a[d][3];
        a[d][3] = 0;
    } else if (a[d][2]==a[d][3]) {
        a[d][2]*= 2;
        a[d][3] = 0;
    }
}

void goRight(int d, int i) {
    for (int j=i-1; j>=0; j--) {
        a[d][j+1] = a[d][j];
    }
    a[d][0] = 0;
}
void clearRight(int d) {
    for (int i=0; i<=3; i++) {
        if (a[d][i] == 0) {
            goRight(d, i);
        }
    }
}
void moveRight(int d) {
    clearRight(d);
    if (a[d][3]==a[d][2]) {
        a[d][3]*= 2;
        a[d][2] = a[d][1];
        a[d][1] = a[d][0];
        a[d][0] = 0;
        if (a[d][2]==a[d][1]) {
            a[d][2]*= 2;
            a[d][1] = 0;
        }
    } else if(a[d][2]==a[d][1]) {
        a[d][2]*= 2;
        a[d][1] = a[d][0];
        a[d][0] = 0;
    } else if (a[d][1]==a[d][0]) {
        a[d][1]*= 2;
        a[d][0] = 0;
    }
}

void goUp(int c, int i) {
    for (int j=i+1; j<=3; j++) {
        a[j-1][c] = a[j][c];
    }
    a[3][c] = 0;
}
void clearUp(int c) {
    for (int i=3; i>=0; i--) {
        if (a[i][c] == 0) {
            goUp(c, i);
        }
    }
}
void moveUp(int c) {
    clearUp(c);
    if (a[0][c]==a[1][c]) {
        a[0][c]*= 2;
        a[1][c] = a[2][c];
        a[2][c] = a[3][c];
        a[3][c] = 0;
        if (a[1][c]==a[2][c]) {
            a[1][c]*= 2;
            a[2][c] = 0;
        }
    } else if(a[1][c]==a[2][c]) {
        a[1][c]*= 2;
        a[2][c] = a[3][c];
        a[3][c] = 0;
    } else if (a[2][c]==a[3][c]) {
        a[2][c]*= 2;
        a[3][c] = 0;
    }
}

void goDown(int c, int i) {
    for (int j=i-1; j>=0; j--) {
        a[j+1][c] = a[j][c];
    }
    a[0][c] = 0;
}
void clearDown(int c) {
    for (int i=0; i<=3; i++) {
        if (a[i][c] == 0) {
            goDown(c, i);
        }
    }
}
void moveDown(int c) {
    clearDown(c);
    if (a[3][c]==a[2][c]) {
        a[3][c]*= 2;
        a[2][c] = a[1][c];
        a[1][c] = a[0][c];
        a[0][c] = 0;
        if (a[2][c]==a[1][c]) {
            a[2][c]*= 2;
            a[1][c] = 0;
        }
    } else if(a[2][c]==a[1][c]) {
        a[2][c]*= 2;
        a[1][c] = a[0][c];
        a[0][c] = 0;
    } else if (a[1][c]==a[0][c]) {
        a[1][c]*= 2;
        a[0][c] = 0;
    }
}

int main() {
    for (i=0; i<4; i++) {
        for (j=0; j<4; j++) {
            cin >> a[i][j];
        }
    }
    cin >> direction;

    for (i=0; i<4; i++) {
        switch (direction) {
            case 0: moveLeft(i);  break;
            case 1: moveUp(i);    break;
            case 2: moveRight(i); break;
            case 3: moveDown(i);  break;
        }
    }

    for (i=0; i<4; i++) {
        if (i > 0) {
            cout << endl;
        }
        for (j=0; j<4; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << a[i][j];
        }
    }
    return 0;
}
