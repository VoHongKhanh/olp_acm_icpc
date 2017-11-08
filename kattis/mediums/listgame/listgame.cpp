#include <iostream>
#include <math.h>

using namespace std;

/*
A List Game

You are playing the following simple game with a friend:
1. The first player picks a positive integer X.
2. The second player gives a list of k positive integers Y1,...,Yk such that (Y1+1)(Y2+1)...(Yk+1)=X, and gets k points.

Write a program that plays the second player.

Input
The input consists of a single integer X satisfying 10^3<=X<=10^9, giving the number picked by the first player.

Output
Write a single integer k, giving the number of points obtained by the second player, assuming she plays as good as possible.

Sample Input 1	Sample Output 1
65536           16

Sample Input 2	Sample Output 2
127381          3
*/

long x, i, s;

int main() {
    cin >> x;

    for (s=0, i=2; i*i <= x;) {
        if (x % i) {
            i++;
        } else {
            x /= i;
            s++;
        }
    }

    if (x > 1) {
        s++;
    }

    cout << s;

    return 0;
}
