#include <iostream>

using namespace std;

/*
Verify This, Your Majesty

The "eight queens puzzle" is a classic puzzle where you have to place eight queens on a chess board in such a way that 
no queen can attack another queen. Remember that, in chess, queens can move in any direction (horizontal, vertical, 
and diagonal), which means the eight queens would have to be laid out in such a way that no two queens are on 
the same row, column, or diagonal.

This puzzle actually has multiple solutions. The following is one possible solution:
    ..*.....
    ....*...
    .*......
    .......*
    *.......
    ......*.
    ...*....
    .....*..
Finding the solutions to the "eight queens puzzle" is actually an interesting computational problem. 
However, that's not the problem you will be solving here. Instead, you will be solving a much simpler problem: 
given a proposed solution to the puzzle, you must verify whether it is a valid solution (i.e., whether no queen can 
attack another queen).

When referring to specific squares on the board, we will assume that the bottom-left square is the (0,0) square, 
and that the x coordinate increases as you move right, and the y coordinate increases as you move up.

In other words, something like this:
    (0,7) ..... ..... ..... (7,7)
    ..... ..... ..... ..... .....
    (0,2) (1,2) (2,2) ..... .....
    (0,1) (1,1) (2,1) ..... .....
    (0,0) (1,0) (2,0) ..... (7,0)

Furthermore, we will consider the more general "N-queens puzzle", where the chessboard can have N x N squares, 
and there will be N queens on the board. For example, this would be a correct solution to the 4-queens puzzle:    
    ..*.
    *...
    ...*
    .*..

And this would be an incorrect solution to the 4-queens puzzle:
    ..*.
    *.*.
    ....
    .*..

Notice how the queen in (2,2) can attack the queen in (0,2) and the queen in (2,3).

Input
The input begins with a line containing a single integer: the value of N (0<N<=5000). This is followed by N lines, 
each containing the position of a queen as two integers: x and y (separated by a single space), where 0<=x,y<N.

Output
The output contains either CORRECT if the positions of the queens is a solution to the N-queens puzzle, 
and INCORRECT otherwise.

Note that the sample data presented below corresponds to the three boards shows earlier.

Sample Input 1	Sample Output 1
8               CORRECT
1 5
6 2
3 1
5 0
4 6
0 3
2 7
7 4

Sample Input 2	Sample Output 2
4               CORRECT
2 3
1 0
0 2
3 1

Sample Input 3	Sample Output 3
4               INCORRECT
2 3
0 2
1 0
2 2
*/

const long MAX  = 5000;
const long MAX2 = MAX*2-1;

int i, d, c, j, n;
char a[MAX][MAX];
bool correct, cot[MAX], cheo_lt_rb[MAX2], cheo_lb_rt[MAX2];

int main() {
    cin >> n;
    for (i=0; i<=n-1; i++) {
        for (j=0; j<=n-1; j++) {
            a[i][j] = '.';
        }
    }
    for (i=0; i<=n-1; i++) {
        cin >> d >> c;
        a[d][c] = '*';
    }

    for (i=0; i<=n-1; i++) {
        cot[i] = true;
    }
    for (i=0; i<=n*2-2; i++) {
        cheo_lt_rb[i] = cheo_lb_rt[i] = true;
    }

    correct = true;
    for (i=0; i<=n-1; i++) {
        c = 0;
        for (j=0; j<=n-1; j++) {
            if (a[i][j] == '*') {
                c++;
                if (cot[j]==false ||
                    cheo_lt_rb[i-j+n-1] == false ||
                    cheo_lb_rt[i+j] == false) {
                    correct = false;
                    break;
                } else {
                    cot[j] = false;
                    cheo_lt_rb[i-j+n-1] = false;
                    cheo_lb_rt[i+j] = false;
                }
            }
        }
        if (c==0 || c>1) {
            correct = false;
            break;
        }
    }

    cout << (correct? "CORRECT": "INCORRECT");
    return 0;
}
