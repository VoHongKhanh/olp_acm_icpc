#include <iostream>
#include <algorithm>

using namespace std;

/*
Trik

Jealous of Mirko's position as head of the village, Borko stormed into his tent and tried to
demonstrate Mirko's incompetence for leadership with a trick.

Borko puts three opaque cups onto the table next to each other (opening facing down) and
a small ball under the leftmost cup. He then swaps two cups in one of three possible ways a number of times.
Mirko has to tell which cup the ball ends up under.

1  2  3     1  2  3     1  2  3
----           ----     -------
   A           B           C

Wise Mirko grins with his arms crossed while Borko struggles to move the cups faster and faster.
What Borko does not know is that programmers in the back are recording all his moves and will
use a simple program to determine where the ball is. Write that program.

Input
The first and only line contains a non-empty string of at most 50 characters, Borko's moves.
Each of the characters is 'A', 'B' or 'C' (without quote marks).

Output
Output the index of the cup under which the ball is: 1 if it is under the left cup, 2 if it is under the middle cup
or 3 if it is under the right cup.

Sample Input 1	Sample Output 1
AB              3

Sample Input 2	Sample Output 2
CBABCACCC       1
*/

string s;
int p1, p2, p3, i;

int main() {
    std::getline(std::cin, s);

    for (p1=1, p2=p3=i=0; i<=s.size()-1; i++) {
        if (s[i] == 'A') {
            std::swap(p1, p2);
        } else if (s[i] == 'B') {
            std::swap(p2, p3);
        } else {
            std::swap(p1, p3);
        }
    }
    cout << (p1? 1: (p2? 2: 3));
    return 0;
}
