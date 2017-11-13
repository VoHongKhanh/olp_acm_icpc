#include <stdio.h>

using namespace std;

/*
An infinite full binary tree labeled by positive rational numbers is defined by:
The label of the root is 1/1.
The left child of label p/q is p/(p+q).
The right child of label p/q is (p+q)/q.

The top of the tree is shown in the following figure:
 v--------------1/1
 -----> 1/2 ----------> 2/1 --------v
 v-----------------------------------
 -> 1/3 --> 3/2 --> 2/3 --> 3/1 --...

A rational sequence is defined by doing a level order (breadth first) traversal of the tree (indicated by the light
dashed line). So that:
    F(1)=1/1, F(2)=1/2, F(3)=2/1, F(4)=1/3, F(5)=3/2, F(6)=2/3,…

Write a program which takes as input a rational number, p/q, in lowest terms and finds the next rational number in
the sequence. That is, if F(n)=p/q, then the result is F(n+1).

Input
The first line of input contains a single integer P, (1<=P<=1000), which is the number of data sets that follow.
Each data set should be processed identically and independently.

Each data set consists of a single line of input. It contains the data set number, K, which is then followed by a space,
then the numerator of the fraction, p, followed immediately by a forward slash (/), followed immediately by the denominator
of the fraction, q. Both pp and q will be relatively prime and 0<=p,q<=2147483647.

Output
For each data set there is a single line of output. It contains the data set number, K, followed by a single space which
is then followed by the numerator of the fraction, followed immediately by a forward slash (/) followed immediately by
the denominator of the fraction. Inputs will be chosen such that neither the numerator nor the denominator will overflow
a 32-bit integer.

Sample Input 1	    Sample Output 1
5                   1 1/2
1 1/1               2 3/2
2 1/3               3 2/5
3 5/2               4 1346269/1860498
4 2178309/1346269   5 10000000/9999999
5 1/10000000
*/

int main() {
    int P, K, i;
    long p, q, depth;

    scanf("%d", &P);

    for (i=1; i<=P; i++) {
        scanf("%d %ld/%ld", &K, &p, &q);

        //special case
        if (p==1 && q==1) {
            p = p;
            q = p+q;
        } else {
            // Go up as long as it is a right child
            depth = p / q;
            p %= q;

            // Go up to parent as left child
            q -= p;

            // Go right
            p += q;

            // Go left until we reach the depth we initially started at
            q += p * depth;
        }

        if (i>1) {
            printf("\n");
        }
        printf("%d %ld/%ld", K, p, q);
    }

    return 0;
}
