#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

/*
Babelfish

You have just moved from Waterloo to a big city. The people here speak an incomprehensible dialect of a foreign language.
Fortunately, you have a dictionary to help you understand them.

Input
Input consists of up to 100000 dictionary entries, followed by a blank line, followed by a message of up to 100000 words.
Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign
word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on
each line. Each word in the input is a non-empty sequence of at most 10 lowercase letters.

Output
Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated
as "eh".

Sample Input 1	Sample Output 1
dog ogday       cat
cat atcay       eh
pig igpay       loops
froot ootfray
loops oopslay

atcay
ittenkay
oopslay
*/

map<string, string> values;
string en, word, s;

int main() {
    while(getline(cin, s) && s != ""){
        stringstream stream(s);
        stream >> en;
        stream >> word;

        values[word] = en;
    }

    while (cin >> word) {
        en = values[word];
        cout << (en==""? "eh": en) << endl;
    }
    return 0;
}
