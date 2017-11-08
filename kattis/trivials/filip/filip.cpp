#include <iostream>

using namespace std;

/*
Filip

Mirko has a younger brother, Filip, who just started going to school and is having trouble with numbers. To help him get
the hang for number scale, his teacher writes two three-digit numbers. She asks Filip to compare those numbers, but instead
of interpreting them with the leftmost most significant digit, he needs to interpret them the other way around, with
the most significant digit being the rightmost one. He than has to tell the teacher the larger of the two numbers.

Write a program that will check Filip's answers.

Input
The first and only line of input contains two three-digit numbers, A and B. A and B will not be equal and will not contain any zeroes.

Output
The first and only line of output should contain the larger of the numbers in the input, compared as described in
the task. The number should be written reversed, to display to Filip how he should read it.

Sample Input 1	Sample Output 1
734 893         437

Sample Input 2	Sample Output 2
221 231         132

Sample Input 3	Sample Output 3
839 237         938
*/

int daonguoc(int n) {
    int dv = n % 10;
    int ch = (n / 10) % 10;
    int tr = n / 100;
    return dv*100 + ch*10 + tr;
}

int main() {
    int a, b;

    cin >> a >> b;
    a = daonguoc(a);
    b = daonguoc(b);
    if (a > b) {
        cout << a;
    } else {
        cout << b;
    }
    return 0;
}
