#include <iostream>

using namespace std;

/*
Eight Queens

In the game of chess, the queen is a powerful piece. It can attack by moving any number of spaces in its current row, 
in its column or diagonally.

In the eight queens puzzle, eight queens must be placed on a standard 8x8 chess board so that no queen can attack another. 
The center figure below shows an invalid solution; two queens can attack each other diagonally. The figure on the right 
shows a valid solution. Given a description of a chess board, your job is to determine whether or not it represents 
a valid solution to the eight queens puzzle.
    ...|.../    *.......    *.......
    \..|../.    ..*.....    ......*.
    .\.|./..    ....*...    ....*...
    ..\|/...    ......*.    .......*
    ---*----    .*......    .*......
    ../|\...    .......*    ...*....
    ./.|.\..    .....*..    .....*..
    /..|..\.    ...*....    ..*.....
    Figure 1: Queen movement (left), invalid solution (center), valid solution (right).

Input
Input will contain a description of a single chess board, given as eight lines of eight characters each. Input lines 
will consist of only the characters '.' and '*'. The '.' character represents an empty space on the board, and the '*' 
character represents a queen.

Output
Print a single line of output. Print the word "valid" if the given chess board is a valid solution to the eight queens 
problem. Otherwise, print "invalid".

Sample Input 1	Sample Output 1
*.......        invalid
..*.....
....*...
......*.
.*......
.......*
.....*..
...*....

Sample Input 2	Sample Output 2
*.......        valid
......*.
....*...
.......*
.*......
...*....
.....*..
..*.....
*/

int i, c, j;
string s;
bool valid, cot[8], cheo_lt_rb[15], cheo_lb_rt[15];

int main() {
    for (i=0; i<=7; i++) {
        cot[i] = true;
    }
    for (i=0; i<=14; i++) {
        cheo_lt_rb[i] = cheo_lb_rt[i] = true;
    }

    valid = true;
    for (i=0; i<=7; i++) {
        cin >> s;

        c = 0;
        for (j=0; j<=7; j++) {
            if (s.at(j) == '*') {
                c++;
                if (cot[j]==false ||
                    cheo_lt_rb[i-j+7] == false ||
                    cheo_lb_rt[i+j] == false) {
                    valid = false;
                    break;
                } else {
                    cot[j] = false;
                    cheo_lt_rb[i-j+7] = false;
                    cheo_lb_rt[i+j] = false;
                }
            }
        }
        if (c==0 || c>1) {
            valid = false;
            break;
        }
    }

    cout << (valid? "valid": "invalid");
    return 0;
}
