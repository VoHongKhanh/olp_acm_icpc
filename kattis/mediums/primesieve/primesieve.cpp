#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

/*
Prime Sieve

Input
The first line of input consists of two integers n, q, where 1<=n<=108 and 1<=q<=20000. Then follow q lines, each containing
an integer x satisfying 1<=x<=n.

Output
On the first line of output, write one line giving the number of prime numbers less than or equal to n. Then for each
query x, output 1 if x is a prime and output 0 if x is composite.

Sample Input 1	Sample Output 1
9973 6          1229
1               0
2               1
3               1
4               0
9972            0
9973            1
*/

#define UPPER_BOUND 100000000
#define MAX 50000001
#define SQRT 10002

long long n, q, counts, i, j;
char isPrime[MAX];

void check_counts(long long n){
    memset(isPrime, 1, MAX);
    counts = 1;
    for(i=3; i<UPPER_BOUND && i<=n; i+=2){
        if(isPrime[i/2]){
            counts++;
            for(j=3*i; j<UPPER_BOUND; j+=(2*i)){
                isPrime[j/2]=false;
            }
        }
    }
}

int is_prime(long long n){
    if(n<2) return 0;
    if(n==2) return 1;
    if(!(n%2)) return 0;
    return isPrime[n/2];
}

int main(){
    scanf("%lld %lld", &n, &q);

    check_counts(n);

    printf("%lld", counts);

    for (i=1; i<=q; i++) {
        scanf("%lld", &n);
        printf("\n%d", is_prime(n));
    }
    return 0;
}
