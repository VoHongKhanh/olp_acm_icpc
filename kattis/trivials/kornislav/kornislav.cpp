#include <iostream>

using namespace std;

/*
Kornislav

Kornislav the turtle never has anything interesting to do. Since he's going to live for three hundred years,
he keeps trying to find way to kill time. This weekend he started playing "enclose the largest rectangle".

To start with, Kornislav needs four positive integers. He tries to enclose a rectangle by moving in one direction,
then turning 90 degrees, then walking in the new direction etc. Kornislav makes a total of three 90-degree turns and
walks four segments.

When walking in some direction, the number of steps he takes must be equal to one of the four chosen integers and each
integer must be used exactly once. Depending on the order in which Kornislav uses the integers, his walk will make various
shapes, some of which don't contain enclosed rectangles. Write a program that calculates the largest rectangle
the turtle can enclose with its walk.

Input
The first line contains four positive integers A,B,CA,B,C and D (0<A,B,C,D<100), the four chosen integers.

Output
Output the largest area.

Sample Input 1	Sample Output 1
1 2 3 4         3

Sample Input 2	Sample Output 2
4 4 3 4         12
*/

int main() {
    int a[4], i, j;

    for (i=0; i<=3; i++) {
        cin >> a[i];
    }

    for (i=0; i<=2; i++) {
        for (j=i+1; j<=3; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }

    cout << min(a[0], a[1]) * min(a[2], a[3]);
    return 0;
}
