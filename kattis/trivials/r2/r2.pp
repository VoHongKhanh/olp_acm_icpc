#include <iostream>

using namespace std;

/*
R2

The number S is called the mean of two numbers R1 and R2 if SS is equal to (R1+R2)/2.
Mirko's birthday present for Slavko was two integers R1 and R2.
Slavko promptly calculated their mean which also happened to be an integer but then lost R2! Help Slavko restore R2.

Input
The first and only line of input contains two integers R1 and SS, both between −1000 and 10001000.

Output
Output R2 on a single line.

Sample Input 1	Sample Output 1
11 15           19

Sample Input 2	Sample Output 2
4 3             2
*/

int r1, s;

int main()
{
    cin >> r1 >> s;

    cout << 2*s - r1;
    return 0;
}
