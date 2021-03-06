#include <iostream>
#include <cmath>

/*
 * We are looking for the number y = n! given n!.
 *
 * The number of digits in a number x is
 *      log(x)+1 if x is a power of 10
 *      ceil(log(x)) otherwise
 * The only factorial numbers that are a power of 10 are 0! and 1!
 * since 2! isn't and the rest have 3 as a factor.
 * log(n!) = log(1 * 2 * ... * n) = log(1) + log(2) + ... + log(n)
*/

using namespace std;

#define E 2.718281828459045235360287471352662497757247093699959574966967627724076630353
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

/*
How Many Digits?

Often times it is sufficient to know the rough size of a number, rather than its exact value. For example, a human can
reason about which store to visit to buy milk if one store is roughly 1 kilometer away, and another store is roughly
100 kilometers away. The exact distance to each store is irrelevant to the decision at hand; only the sizes of
the numbers matter.

For this problem, determine the 'size' of the factorial of an integer. By size, we mean the number of digits required to
represent the answer in base-10.

Input
Input consists of up to 10000 integers, one per line. Each is in the range [0,1000000]. Input ends at end of file.

Output
For each integer n, print the number of digits required to represent n! in base-10.

Sample Input 1	Sample Output 1
0               1
1               1
3               1
10              7
20              19
*/

int main() {
    int n;
    while(cin >> n) {
        cout << (n < 2 ? 1 : (long)ceil(log10(2*PI*n)/2+n*(log10(n/E)))) << endl;
    }
    return 0;
}
