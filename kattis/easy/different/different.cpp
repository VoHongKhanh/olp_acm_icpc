#include <iostream>

using namespace std;

/*
A Different Problem

Write a program that computes the difference between non-negative integers.

Input
Each line of the input consists of a pair of integers. Each integer is between 0 and 1015 (inclusive). The input is
terminated by end of file.

Output
For each pair of integers in the input, output one line, containing the absolute value of their difference.

Sample Input 1	        Sample Output 1
10 12                   2
71293781758123 72784    71293781685339
1 12345677654321        12345677654320
*/

long long int a, b;
bool first = true;

int main() {
    while(cin >> a >> b) {
        if (!first) {
            cout << endl;
        }
        cout << (a > b? a - b: b - a);
        first = false;
    }

    return 0;
}
