#include <iostream>

using namespace std;

/*
Reversed Binary Numbers

Yi has moved to Sweden and now goes to school here. The first years of schooling she got in China, and the curricula
do not match completely in the two countries. Yi likes mathematics, but now... The teacher explains the algorithm for
subtraction on the board, and Yi is bored. Maybe it is possible to perform the same calculations on the numbers
corresponding to the reversed binary representations of the numbers on the board? Yi dreams away and starts constructing
a program that reverses the binary representation, in her mind. As soon as the lecture ends, she will go home and
write it on her computer.

Task
Your task will be to write a program for reversing numbers in binary. For instance, the binary representation of
13 is 1101, and reversing it gives 1011, which corresponds to number 11.

Input
The input contains a single line with an integer N, 1<=N<=1 000 000 000.

Output
Output one line with one integer, the number we get by reversing the binary representation of N.

Sample Input 1	Sample Output 1
13              11

Sample Input 2	Sample Output 2
47              61
*/

long n, m;

int main() {
    cin >> n;

    m = 0;
    while(n > 0) {
        m = m*2 + n%2;
        n /= 2;
    }

    cout << m;

    return 0;
}
