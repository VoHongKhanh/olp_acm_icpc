#include <iostream>

using namespace std;

/*
Hissing Microphone

A known problem with some microphones is the "hissing s". That is, sometimes the sound of the letter s is particularly 
pronounced; it stands out from the rest of the word in an unpleasant way.

Of particular annoyance are words that contain the letter s twice in a row. Words like amiss, kiss, mississippi and even 
hiss itself.

Input
The input contains a single string on a single line. This string consists of only lowercase letters (no spaces) and has 
between 1 and 30 characters.

Output
Output a single line. If the input string contains two consecutive occurrences of the letter s, then output hiss. 
Otherwise, output no hiss.

Sample Input 1	Sample Output 1
amiss           hiss

Sample Input 2	Sample Output 2
octopuses       no hiss

Sample Input 3	Sample Output 3
hiss            hiss
*/

unsigned int i;
bool isHiss;
string s;

int main() {
    cin >> s;

    isHiss = false;
    for (i=1; i<=s.length()-1; i++) {
        if (s.at(i-1)=='s' && s.at(i)=='s') {
            isHiss = true;
            break;
        }
    }
    if (isHiss) {
        cout << "hiss";
    } else {
        cout << "no hiss";
    }
    return 0;
}
