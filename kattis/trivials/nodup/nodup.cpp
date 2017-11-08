#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
No Duplicates

There is a game in which you try not to repeat a word while your opponent tries to see if you have repeated one.
"THE RAIN IN SPAIN" has no repeats.
"IN THE RAIN AND THE SNOW" repeats THE.
"THE RAIN IN SPAIN IN THE PLAIN" repeats THE and IN.

Write a program to test a phrase.

Input
Input is a line containing words separated by single spaces, where a word consists of one or more uppercase letters.
A line contains no more than 80 characters.

Output
The output is "yes" if no word is repeated, and "no" if one or more words repeat.

Sample Input 1	                    Sample Output 1
THE RAIN IN SPAIN                   yes

Sample Input 2	                    Sample Output 2
IN THE RAIN AND THE SNOW            no

Sample Input 3	                    Sample Output 3
THE RAIN IN SPAIN IN THE PLAIN      no
*/

vector<string> a;
string s, token;

bool myfind(string token) {
    for (vector<string>::iterator it = a.begin() ; it != a.end(); ++it) {
        if (token == *it) {
            return false;
        }
    }
    return true;
}

int main() {
    std::getline(std::cin, s);

    string delimiter = " ";

    size_t pos = 0;
    bool result = true;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);

        result = myfind(token);
        if (result == false) {
            break;
        } else {
            a.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
    }
    if (result) {
        result = myfind(s);
    }

    cout << (result? "yes": "no");

    return 0;
}
