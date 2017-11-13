#include <iostream>

using namespace std;

/*
Quick Estimates

Let's face it... you are not that handy. When you need to make a major home repair, you often need to hire someone to
help. When they come for the first visit, they make an estimate of the cost. Here they must be careful: if they
overestimate the cost, it might scare you off, but if they underestimate, the work might not be worth their time.

Because the worker is so careful, it can take a long time for them to produce the estimate. But that's frustrating - when
you ask for an estimate, you really are asking for the magnitude of the cost. Will this be $10 or $100 or $1000?
That's all you really want to know on a first visit.

Please help the worker make the type of estimate you desire. Write a program that, given the worker's estimate,
reports just the magnitude of the cost - the number of digits needed to represent the estimate.

Input
Input begins with a line containing an integer N (1<=N<=100). The next N lines each contain one estimated cost,
which is an integer between 0 and 10^100. (Some of the workers overcharge quite a bit.)

Output
For each estimated cost, output the number of digits required to represent it.

Sample Input 1	Sample Output 1
5               3
314             1
1               4
5926            1
5               5
35897

Sample Input 2	Sample Output 2
3               1
0               2
10              3
100
*/

bool first;
int n, i;
string s;

int main() {
    cin >> n;
    cin.ignore();

    first = true;
    for(i=1; i<=n; i++) {
        cin >> s;

        if(!first) {
            cout << endl;
        }
        cout << s.length();
        first = false;
    }

    return 0;
}
