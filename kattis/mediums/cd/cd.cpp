#include <iostream>

using namespace std;

/*
CD

Jack and Jill have decided to sell some of their Compact Discs, while they still have some value. They have decided to 
sell one of each of the CD titles that they both own. How many CDs can Jack and Jill sell?

Neither Jack nor Jill owns more than one copy of each CD.

Input
The input consists of a sequence of test cases. The first line of each test case contains two non-negative integers N and M, 
each at most one million, specifying the number of CDs owned by Jack and by Jill, respectively. This line is followed by 
N lines listing the catalog numbers of the CDs owned by Jack in increasing order, and M more lines listing the catalog 
numbers of the CDs owned by Jill in increasing order. Each catalog number is a positive integer no greater than 
one billion. The input is terminated by a line containing two zeros. This last line is not a test case and should not 
be processed.

Output
For each test case, output a line containing one integer, the number of CDs that Jack and Jill both own.

Sample Input 1	Sample Output 1
3 3             2
1
2
3
1
2
4
0 0
*/

const int MAX = 1000000000 / 32;

int a[MAX];
int n, m, jack, jill, c;
bool first;

void reset() {
    for (int i=0; i<=MAX-1; i++) {
        a[i] = 0;
    }
}
void put(int p) {
    a[p/8] = (1 << (p%8)) | a[p/8];
}
bool get(int p) {
    return (a[p/8] >> (p%8)) & 1;
}

int main() {
    first = true;
    while(cin >> n >> m) {
        if (n==0 && m==0) {
            break;
        } else {
            reset();

            for (int i=1; i<=n; i++) {
                cin >> jack;
                put(jack-1);
            }

            c = 0;
            for (int i=1; i<=n; i++) {
                cin >> jill;
                if (get(jill-1)) {
                    c++;
                }
            }
            if (!first) {
                cout << endl;
            }
            cout << c;
            first = false;
        }
    }

    return 0;
}
