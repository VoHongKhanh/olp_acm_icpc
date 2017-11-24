#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 * We are looking for the number y = n! given n!.
 *
 * The number of digits in a number x is
 *      log(x)+1 if x is a power of 10
 *      ceil(log(x)) otherwise
 * The only factorial numbers that are a power of 10 are 0! and 1!
 * since 2! isn't and the rest have 3 as a factor.
 *
 * After 9!, each number is the previous multiplied by at least 10
 * which makes it's digit count unique. There are some non-unique
 * digit counts in the early numbers:
 * 0! = 1
 * 1! = 1
 * 2! = 2
 * 3! = 6
 * 4! = 24
 * 5! = 120
 * 6! = 720
 * 7! = 5040
 * 8! = 40320
 * 9! = 936880
 *
 * Now we only need to check when we have reached the same number of
 * digits as our desired number and to do that, we can use the
 * following identity: log(n!) = log(1 * 2 * ... * n) = log(1) + log(2) + ... + log(n)
 */

using namespace std;

/*
Inverse Factorial

A factorial n! of a positive integer n is defined as the product of all positive integers smaller than or equal to n.
For example,
    21! = 1*2*3*...*21 = 51090942171709440000.
It is straightforward to calculate the factorial of a small integer, and you have probably done it many times before.
In this problem, however, your task is reversed. You are given the value of n! and you have to find the value of n.

Input
The input contains the factorial n! of a positive integer n. The number of digits of n! is at most 10^6.

Output
Output the value of n.

Sample Input 1	                Sample Output 1
120                             5

Sample Input 2	                Sample Output 2
51090942171709440000            21

Sample Input 3	                Sample Output 3
10888869450418352160768000000   27
*/

string s;
unsigned long n;
long number;
double sum;

int main() {
    cin >> s;

    n = s.length();
    if (n < 4) {
        cout << (s == "1"? 1: s=="2"? 2: s=="6"? 3: s=="24"? 4: s=="120"? 5: 6);
    } else {
        //sum = log10(1) + log10(2) + log10(3) + log10(4) + log10(5) + log10(6);
        //sum =        0 + log10(2) + log10(3) + log10(2) + log10(2) + log10(5) + log10(2) + log10(3);
        sum = 4*log10(2) + 2*log10(3) + log10(5);

        number = 6;
        while (true) {
            number++;
            sum += log10(number);
            if (sum > n) {
                cout << number - 1;
                break;
            }
        }
    }
    return 0;
}
