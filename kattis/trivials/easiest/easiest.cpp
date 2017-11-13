#include <iostream>

using namespace std;

/*
The Easiest Problem Is This One

Some people think this is the easiest problem in today’s problem set. Some people think otherwise, since it involves sums of digits of numbers and that’s difficult to grasp.

If we multiply a number N with another number m, the sum of digits typically changes. For example, if m=26 and N=3029, then N.m=78754 and the sum of the digits is 31, while the sum of digits of N is 14.

However, there are some numbers that if multiplied by N will result in the same sum of digits as the original number N. For example, consider m=37, N=3029, then N.m=112073, which has sum of digits 14, same as the sum of digits of N.

Your task is to find the smallest positive integer pp among those that will result in the same sum of the digits when multiplied by N. To make the task a little bit more challenging, the number must also be higher than ten.

Input
The input consists of several test cases. Each case is described by a single line containing one positive integer number N, 1<=N<=100000. The last test case is followed by a line containing zero.

Output
For each test case, print one line with a single integer number p which is the minimal number such that N.p has the same sum of digits as N and p is bigger than 10.

Sample Input 1	Sample Output 1
3029            37
4               28
5               28
42              25
0
*/

long long n, p, s;
bool first;

long long sum(long long n) {
    long long s = 0;
    while (n>9) {
        s += n % 10;
        n /= 10;
    }
    s += n;
    return s;
}

int main() {
    first = true;
    do {
        cin >> n;

        s = sum(n);
        if (n > 0) {
            if (!first) {
                cout << endl;
            }

            for (p=11; true; p++) {
                if (s == sum(n*p)) {
                    cout << p;
                    break;
                }
            }
            first = false;
        }
    } while (n != 0);

    return 0;
}
