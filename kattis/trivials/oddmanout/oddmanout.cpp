#include <iostream>

using namespace std;

/*
Odd Man Out

You are hosting a party with G guests and notice that there is an odd number of guests! When planning the party you
deliberately invited only couples and gave each couple a unique number C on their invitation. You would like to
single out whoever came alone by asking all of the guests for their invitation numbers.

Input
The first line of input gives the number of cases, N. N test cases follow. For each test case there will be:
# One line containing the value G the number of guests.
# One line containing a space-separated list of G integers. Each integer C indicates the invitation code of a guest.
  You may assume that 1<=N<=50,0<C<231,3<=G<1000.

Output
For each test case, output one line containing "Case #x: " followed by the number C of the guest who is alone.

Sample Input 1	            Sample Output 1
3                           Case #1: 1
3                           Case #2: 7
1 2147483647 2147483647     Case #3: 5
5
3 4 7 4 3
5
2 10 2 10 5
*/

unsigned long n, g, c, v, i, j;

int main() {
    cin >> n;

    for (i=1; i<=n; i++) {
        cin >> g;

        v = 0;
        for (j=1; j<=g; j++) {
            cin >> c;
            v ^= c;
        }

        if (i > 1) {
            cout << endl;
        }
        cout << "Case #" << i << ": " << v;
    }
    return 0;
}
