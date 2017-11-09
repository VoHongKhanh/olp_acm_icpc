#include <iostream>

using namespace std;

/*
Dice Cup

In many table-top games it is common to use different dice to simulate random events. A "d" or "D" is used to indicate
a die with a specific number of faces, d4 indicating a four-sided die, for example. If several dice of the same type are
to be rolled, this is indicated by a leading number specifying the number of dice. Hence, 2d6 means the player should roll
two six-sided dice and sum the result face values.

Task
Write a program to compute the most likely outcomes for the sum of two dice rolls. Assume each die has numbered faces
starting at 1 and that each face has equal roll probability.

Input
The input consists of a single line with two integer numbers, N,M, specifying the number of faces of the two dice.

Constraints
4<=N,M<=20 Number of faces.

Output
A line with the most likely outcome for the sum; in case of several outcomes with the same probability, they must be
listed from lowest to highest value in separate lines.

Sample Input 1	Sample Output 1
6 6             7

Sample Input 2	Sample Output 2
6 4             5
                6
                7

Sample Input 3	Sample Output 3
12 20           13
                14
                15
                16
                17
                18
                19
                20
                21
*/

int n, m, i, a, b;

int main() {
    cin >> n >> m;

    a = n < m? n: m;
    b = n > m? n: m;
    for (i=a+1; i<=b+1; i++) {
        if (i > a+1) {
            cout << endl;
        }
        cout << i;
    }

    return 0;
}
