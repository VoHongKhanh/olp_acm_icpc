#include <iostream>

using namespace std;

/*
Kemija

Luka is fooling around in chemistry class again! Instead of balancing equations he is writing coded sentences on
a piece of paper. Luka modifies every word in a sentence by adding, after each vowel (letters 'a', 'e', 'i', 'o' and 'u'),
the letter 'p' and then that same vowel again. For example, the word "kemija" becomes "kepemipijapa" and the word "paprika"
becomes "papapripikapa". The teacher took Luka's paper with the coded sentences and wants to decode them.

Write a program that decodes Luka's sentence.

Input
The coded sentence will be given on a single line. The sentence consists only of lowercase letters of
the English alphabet and spaces. The words will be separated by exactly one space and there will be no leading or trailing
spaces. The total number of character will be at most 100.

Output
Output the decoded sentence on a single line.

Sample Input 1	                                    Sample Output 1
zepelepenapa papapripikapa                          zelena paprika

Sample Input 2	                                    Sample Output 2
bapas jepe doposapadnapa opovapa kepemipijapa       bas je dosadna ova kemija
*/

string s;
unsigned int i;

int main() {
    std::getline(std::cin, s);

    if (s.length() < 3) {
        cout << s;
    } else {
        for(i=0; i<=s.length()-1; ) {
            cout << s.at(i);
            if ((s.at(i)=='a' ||
                 s.at(i)=='e' ||
                 s.at(i)=='o' ||
                 s.at(i)=='u' ||
                 s.at(i)=='i') &&
                s.at(i) == s.at(i+2) &&
                s.at(i+1)=='p') {
                i += 3;
            } else {
                i++;
            }
        }
    }
    return 0;
}
