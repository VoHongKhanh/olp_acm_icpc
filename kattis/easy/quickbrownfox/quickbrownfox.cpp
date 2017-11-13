#include <iostream>

using namespace std;

/*
Quick Brown Fox

A pangram is a phrase that includes at least one occurrence of each of the 26 letters, 'a'...'z'. You're probably
familiar with this one: "The quick brown fox jumps over the lazy dog."

Your job is to recognize pangrams. For phrases that don't contain every letter, report what letters are missing.
We'll say that a particular letter occurs in the phrase if it occurs as either upper case or lower case.

Input
Input starts with a line containing an integer 1<=N<=50. The next N lines are each a single phrase, possibly containing
upper and lower case letters, spaces, decimal digits and punctuation characters '.', ',', '?', '!', ''' and '"'.
Each phrase contains at least one and no more than 100 characters.

Output
For each input phrase, output "pangram" if it qualifies as a pangram.
Otherwise, output the word "missing" followed by a space and then the list of letters that didn't occur in the phrase.
The list of missing letters should be reported in lower case and should be sorted alphabetically.

Sample Input 1	                                Sample Output 1
3                                               pangram
The quick brown fox jumps over the lazy dog.    missing eq
ZYXW, vu TSR Ponm lkj ihgfd CBA.                missing klmnopqrstuvwxyz
.,?!'" 92384 abcde FGHIJ
*/

bool c[26], first;
unsigned int n, i, j, d;
string s;
char ch;

int main() {
    cin >> n;
    cin.ignore();

    first = true;
    for (i=1; i<=n; i++) {
        std::getline(std::cin, s);

        for (j='a'-'a'; j<='z'-'a'; j++) {
            c[j] = false;
        }
        d = 0;
        for (j=0; j<=s.length()-1; j++) {
            ch = s.at(j);
            if ('A'<=ch && ch<='Z') {
                ch += 'a' - 'A';
            }

            if ('a'<=ch && ch<='z') {
                if (c[ch-'a'] == false) {
                    c[ch-'a'] = true;
                    d++;
                }
            }
        }

        if (!first) {
            cout << endl;
        }
        if (d == 26) {
            cout << "pangram";
        } else {
            cout << "missing ";
            for (j='a'-'a'; j<='z'-'a'; j++) {
                if (c[j] == false) {
                    cout << (char)(j+'a');
                }
            }
        }
        first = false;
    }

    return 0;
}
