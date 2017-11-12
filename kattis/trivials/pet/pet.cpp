#include <iostream>

using namespace std;

/*
Pet
In the popular show "Dinner for Five", five contestants compete in preparing culinary delights. Every evening one of 
them makes dinner and each of other four then grades it on a scale from 1 to 5. The number of points a contestant gets is 
equal to the sum of grades they got. The winner of the show is of course the contestant that gets the most points.

Write a program that determines the winner and how many points they got.

Input
Five lines, each containing 4 integers, the grades a contestant got. The contestants are numbered 1 to 5 in the order in 
which their grades were given.

Output
Output on a single line the winner's number and their points, separated by a space. The input data will guarantee that 
the solution is unique.

Sample Input 1	Sample Output 1
5 4 4 5         4 19
5 4 4 4
5 5 4 4
5 5 5 4
4 4 4 5

Sample Input 2	Sample Output 2
4 4 3 3         2 17
5 4 3 5
5 5 2 4
5 5 5 1
4 4 4 4
*/

int main() {
    int winner, maxp, p, p1, p2, p3, p4, i;

    for (winner=1,maxp=0,i=1; i<=5; i++) {
        cin >> p1 >> p2 >> p3 >> p4;
        p = p1+p2+p3+p4;
        if (p > maxp) {
            maxp = p;
            winner = i;
        }
    }

    cout << winner << " " << maxp;

    return 0;
}
