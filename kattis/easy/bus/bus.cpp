#include <iostream>

using namespace std;

/*
Bus
A bus with n passengers opens its door at the bus stop. Exactly half of its passengers and an additional half of
a passenger get out. On the next stop, again, half of the passengers plus half of a passenger leave the bus.
This goes on for k stops in total. Knowing that the bus leaves the last stop empty, and that no one was hurt
during the trip, determine the initial number n of people in the bus.

Input
The first line of input contains the number of test cases T. The descriptions of the test cases follow:
The only line of each test case contains the number of stops k, 1<=k<=30.

Output
For each test case, output a single line containing a single integer-the initial number of bus passengers.

Sample Input 1	Sample Output 1
2               1
1               7
3
*/

long t, k, i;

int main() {
    cin >> t;

    for (i=1; i<=t; i++) {
        cin >> k;
        if (i > 1) {
            cout << endl;
        }
        cout << ((1 << k) - 1);
    }
    return 0;
}
