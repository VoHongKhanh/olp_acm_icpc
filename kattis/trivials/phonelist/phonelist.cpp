#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

/*
Phone List
Given a list of phone numbers, determine if it is consistent in the sense that no number is the prefix of another.
Let's say the phone catalogue listed these numbers:
    # Emergency 911
    # Alice 97 625 999
    # Bob 91 12 54 26
In this case, it's not possible to call Bob, because the central would direct your call to the emergency line as soon as
you had dialled the first three digits of Bob's phone number. So this list would not be consistent.

Input
The first line of input gives a single integer, 1<=t<=40, the number of test cases. Each test case starts with n,
the number of phone numbers, on a separate line, 1<=n<=10000. Then follows n lines with one unique phone number on
each line. A phone number is a sequence of at most ten digits. Note that leading zeros in phone numbers are significant,
e.g., "0911" is a different phone number than "911".

Output
For each test case, output "YES" if the list is consistent, or "NO" otherwise.

Sample Input 1	Sample Output 1
2               NO
3               YES
911
97625999
91125426
5
113
12340
123440
12345
98346
*/

struct Trie {
    bool end;
    Trie *children[10];
    Trie() {
        end = false;
        for (int i = 0; i < 10; ++i) {
            children[i] = NULL;
        }
    }
    bool isEnd() { return end; }
};

bool addWord(Trie &root, string w) {
    Trie *trie = &root;
    bool collision = true;
    char c;

    for (unsigned int j=0; j<=w.length()-1; j++) {
        c = w.at(j);

        int i = c - '0';
        if (trie->children[i] != NULL) {
            if (trie->children[i]->isEnd()) {
                return collision = true;
            }
        }
        else {
            trie->children[i] = new Trie();
            collision = false;
        }
        trie = trie->children[i];
    }
    trie->end = true;
    return collision;
}

void freeTrie(Trie *trie) {
    for (int i = 0; i < 10; ++i) {
        if (trie->children[i] != NULL)
            freeTrie(trie->children[i]);
        delete(trie->children[i]);
    }
}

int main() {
    int T, N;
    string line;

    cin >> T;
    for (int i = 0; i < T; ++i) {
        Trie root;
        bool collision = false;

        cin >> N;
        getline(cin, line);

        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            if (addWord(root, line)) {
                collision = true;
            }
        }
        if (collision) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        freeTrie(&root);
    }
    return 0;
}
