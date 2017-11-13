#include <iostream>

using namespace std;

/*
Tri

Little Mirko wrote into his math notebook an equation containing three positive integers, the equals sign and one of
the four basic arithmetic operations (addition, subtraction, multiplication and division).

During another class, his friend Slavko erased the equals sign and the operations from Mirko's notebook. Help Mirko by
reconstructing the equation from the three integers

Input
The first line of input contains three integers less than 100, separated by spaces. The input data will guarantee
that a solution, although not necessarily unique, will always exist.

Output
On a single line, output a valid equation containing the three integers (in the same order), an equals sign and one of
the four operations. If there are multiple solutions, output any of them.

Sample Input 1	Sample Output 1
5 3 8           5+3=8

Sample Input 2	Sample Output 2
5 15 3          5=15/3
*/

int a, b, c;

int main() {
    cin >> a >> b >> c;

    if (a+b == c) {
        cout << a << "+" << b << "=" << c;
    } else if (a-b == c) {
        cout << a << "-" << b << "=" << c;
    } else if (a*b == c) {
        cout << a << "*" << b << "=" << c;
    } else if (a/b == c) {
        cout << a << "/" << b << "=" << c;
    } else if (a == b + c) {
        cout << a << "=" << b << "+" << c;
    } else if (a == b - c) {
        cout << a << "=" << b << "-" << c;
    } else if (a == b * c) {
        cout << a << "=" << b << "*" << c;
    } else if (a == b / c) {
        cout << a << "=" << b << "/" << c;
    }
    return 0;
}
