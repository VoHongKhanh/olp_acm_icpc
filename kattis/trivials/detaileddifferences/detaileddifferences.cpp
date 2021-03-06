#include <iostream>

using namespace std;

/*
Detailed Differences

One of the most basic problems in information processing is identifying differences between data. This is useful when
comparing files, for example. For this problem, write a program which identifies the differences between pairs of
strings to make it easier for humans to see the differences.

Your program should identify those characters which differ between the two given strings in a visually striking way.
Output the two input strings on two lines, and then identify the differences on the line below using periods
(for identical characters) and asterisks (for differing characters). For example:
    ATCCGCTTAGAGGGATT
    GTCCGTTTAGAAGGTTT
    *....*.....*..*..

Input
The first line of input contains an integer 1<=n<=500, indicating the number of test cases that follow. Each test case is
a pair of lines of the same length, 1 to 50 characters. Each string contains only letters (a-z, A-Z) or digits (0-9).

Output
For each test case, output the two lines in the order they appear in the input. Output a third line indicating similarities
and differences as described above. Finally, output a blank line after each test case.

Sample Input 1	                            Sample Output 1
3                                           ATCCGCTTAGAGGGATT
ATCCGCTTAGAGGGATT                           GTCCGTTTAGAAGGTTT
GTCCGTTTAGAAGGTTT                           *....*.....*..*..
abcdefghijklmnopqrstuvwxyz
bcdefghijklmnopqrstuvwxyza                  abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxyz0123456789        bcdefghijklmnopqrstuvwxyza
abcdefghijklmnopqrstuvwxyz0123456789        **************************

                                            abcdefghijklmnopqrstuvwxyz0123456789
                                            abcdefghijklmnopqrstuvwxyz0123456789
                                            ....................................
*/

unsigned int n, i, j;
string s1, s2;

int main() {
    cin >> n;
    cin.ignore();

    for (i=1; i<=n; i++) {
        cin >> s1 >> s2;

        if (i > 1) {
            cout << endl << endl;
        }
        cout << s1 << endl << s2 << endl;
        for (j=0; j<=s1.length()-1; j++) {
            if (s1.at(j) == s2.at(j)) {
                cout << ".";
            } else {
                cout << "*";
            }
        }
    }
    return 0;
}
