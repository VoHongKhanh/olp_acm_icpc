#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/*
Goldbach's Conjecture

The goal of this program is to find all unique ways to represent a given even number as the sum of two prime numbers.
A prime number is an integer greater than 1 that is evenly divisible by only itself and 1. The first few prime numbers
are 2, 3, 5, 7, 11,…The German mathematician Christian Goldbach (1690-1764) conjectured that every even number greater
than 2 can be represented by the sum of two prime numbers. (This conjecture has never been proved nor has a counterexample
ever been found. As such, you may assume it is true for the cases considered in this problem.) There may be several ways to
represent a given even number by the sum of primes. For example, the even number 26 may be represented
as 3 + 23, 7 + 19, or 13 + 13.

Input
Input starts with an integer n (1<=n<=100) indicating the number of cases. The following n lines each contain a test case
of a single even number x (4<=x<=32000).

Output
For each test case x, give the number of unique ways that x can be represented as a sum of two primes. Then list the sums
(one sum per line) in increasing order of the first addend. The first addend must always be less than or equal to the second
to avoid duplicates. Print a blank line between each pair of test cases.

Sample Input 1	Sample Output 1
3               4 has 1 representation(s)
4               2+2
26
100             26 has 3 representation(s)
                3+23
                7+19
                13+13

                100 has 6 representation(s)
                3+97
                11+89
                17+83
                29+71
                41+59
                47+53
*/

bool primes[32001];
int i, j, v, x, n;

void khoitao() {
    memset (primes, true, 32001);
    primes[0] = primes[1] = false;
    i = 2;
    while (i < 32000) {
        while (i < 32000 && !primes[i]) {
            i++;
        }
        if (i < 32000) {
            j=2;
            v = i*j;
            while (v <= 32000) {
                primes[v] = false;
                j++;
                v = i*j;
            }
            i++;
        }
    }
}

int main() {
    khoitao();

    cin >> n;

    for (i=1; i<=n; i++) {
        cin >> x;

        vector<int> a;
        for (j=1; j<=x/2; j++) {
            if (primes[j] && primes[x-j]) {
                a.push_back(j);
            }
        }

        cout << x << " has " << a.size() << " representation(s)" << endl;
        for(j=0; j<a.size(); j++) {
            cout << a[j] << "+" << x-a[j] << endl;
        }
        cout << endl;
    }

    return 0;
}
