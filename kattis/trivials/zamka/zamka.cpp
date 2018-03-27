#include <stdio.h>
using namespace std;

/*
Zamka

The impossible has happened. Bear G. has fallen into his own trap. Lured by a delicious box of Domacica, without even thinking, 
he rushed and fell into his trap. In order to get out of the trap, he must solve the following task with your help. You are given three 
integers L, D and X.
  # Determine the minimal integer N such that L<=N<=D and the sum of its digits is X
  # Determine the maximal integer M such that L<=M<=D and the sum of its digits is X
Bear will be able to escape from the trap if he correctly determines numbers N and M. The numbers N and M will always exist.

Input
The first line of input contains the integer L (1<=L<=10000), the number from the task. The second line of input contains 
the integer D (1<=D<=10000, L<=D), the number from the task. The third line of input contains the integer X (1<=X<=36), 
the number from the task.

Output
The first line of output must contain the integer N from the task. The second line of output must contain the integer M from the task.

Sample Input 1	  Sample Output 1
1                 4
100               40
4

Sample Input 2	  Sample Output 2
100               129
500               480
12

Sample Input 3	  Sample Output 3
1                 1
10000             10000
1
*/

int sum(int n) {
	int s = 0;
	while (n > 9) {
		s += n%10;
		n /= 10;
	}
	return s+n;
}

int main() {
	int L, D, X, N, M;
	
	scanf("%d%d%d", &L, &D, &X);
	
	for (N=L; N<=D; N++) {
		if (sum(N)==X) {
			break;
		}
	}
	for(M=D; M>=N; M--) {
		if (sum(M)==X) {
			break;
		}
	}
	printf("%d\n%d", N, M);
	return 0;
}
