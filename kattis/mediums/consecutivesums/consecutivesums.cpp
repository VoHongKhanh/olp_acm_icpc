#include <stdio.h>

/*
Sums

Given an integer N, express it as the sum of at least two consecutive positive integers.
For example:
    10 = 1 + 2 + 3 + 4
    24 = 7 + 8 + 9
If there are multiple solutions, output the one with the smallest possible number of summands.

Input
The first line of input contains the number of test cases T (1<=T<=2000). The descriptions of the test cases follow:
Each test case consists of one line containing an integer N (1<=N<=109).

Output
For each test case, output a single line containing the equation
in the format N = a + (a+1) + ... + b as in the example.
If there is no solution, output a single word IMPOSSIBLE instead.

Sample Input 1	Sample Output 1
3               IMPOSSIBLE
8               10 = 1 + 2 + 3 + 4
10              24 = 7 + 8 + 9
24
*/

using namespace std;

/* (a) + (a+1) + (a+2) + ... + (b-1) + (b) */
int sum_ab(int a, int b) {
    return (b*(b+1) - a*(a-1)) >> 1;
}

int check_sum(int n, int k, int start) {
    return sum_ab(start + 1, start + k) == n ? start + 1 :
           sum_ab(start, start + k - 1) == n ? start     : 0;
}

void sum_search(int n) {
    int k = 2, start;
    while (!(start = check_sum(n, k, n/k - (k>>1))))
        k++;
    printf("%d = %d", n, start);
    for (int i = start + 1; i < start + k; i++)
        printf(" + %d", i);
    printf("\n");
}

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n & (n - 1))
            sum_search(n);
        else // impossible for {2^i | i in N}
            printf("IMPOSSIBLE\n");
    }
}
