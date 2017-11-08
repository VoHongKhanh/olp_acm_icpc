#include <iostream>
#include <math.h>

using namespace std;

/*
Pot

The teacher has sent an e-mail to her students with the following task: "Write a program that will determine and output the value of X if given the statement:

X=number^pow1 + number^pow2 + ... + number^powN

and it holds that number1, number2 to numberN are integers, and pow1, pow2 to powN are one-digit integers."
Unfortunately, when the teacher downloaded the task to her computer, the text formatting was lost so the task transformed into a sum of N integers:

X = P1 + P2 + ... + PN
X = P1 + P2 + ... + PN
For example, without text formatting, the original task in the form of X=212+1253X=212+1253 became a task in the form of X=212+1253X=212+1253. Help the teacher by writing a program that will, for given NN integers from P1P1 to PNPN determine and output the value of XX from the original task.

Input
The first line of input contains the integer N (1<=N<=10), the number of the addends from the task.
Each of the following N lines contains the integer Pi (10<=Pi<=9999, i=1, ..., Ni=1, ..., N) from the task.

Output
The first and only line of output must contain the value of X (X<=1000000000) from the original task.

Sample Input 1	Sample Output 1
2               1953566
212
1253

Sample Input 2	Sample Output 2
5               102
23
17
43
52
22

Sample Input 3	Sample Output 3
3               10385
213
102
45
*/
int n, p, xi, pi, i;
long x;

int main() {
    cin >> n;

    for (x = 0, i=1; i<=n; i++) {
        cin >> p;
        xi = p / 10;
        pi = p % 10;
        x += (long)pow(xi, pi);
    }
    cout << x;
    return 0;
}
