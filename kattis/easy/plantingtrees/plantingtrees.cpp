#include <iostream>
#include <algorithm>

using namespace std;

/*
Planting Trees

Farmer Jon has recently bought n tree seedlings that he wants to plant in his yard. It takes 1 day for Jon to plant
a seedling1, and for each tree Jon knows exactly in how many days after planting it grows to full maturity.
Jon would also like to throw a party for his farmer friends, but in order to impress them he would like to organize
the party only after all the trees have grown. More precisely, the party can be organized at earliest on
the next day after the last tree has grown up.

Help Jon to find out when is the earliest day when the party can take place. Jon can choose the order of planting
the trees as he likes, so he wants to plant the trees in such a way that the party will be as soon as possible.

Input
The input consists of two lines. The first line contains a single integer N (1<=N<=100000) denoting the number of
seedlings. Then a line with N integers t_i follows (1<=t_i<=1000000), where t_i denotes the number of days it takes for
the i^th tree to grow.

Output
You program should output exactly one line containing one integer, denoting the earliest day when the party can
be organized. The days are numbered 1, 2, 3, ... beginning from the current moment.

Sample Input 1	    Sample Output 1
4                   7
2 3 4 3

Sample Input 2	    Sample Output 2
6                   42
39 38 9 35 39 20

Footnotes
1. Jon isn’t particularly hardworking.
*/

const int MAX = 100000;

int n, i;
long t[MAX];

int cmp (const void * a, const void * b) {
     return ( *(long*)b - *(long*)a );
}

int main() {
    cin >> n;
    for(i=0; i<=n-1; i++) {
        cin >> t[i];
    }

    qsort(t, n, sizeof(long), cmp);

    long day = 0;
    for (i=0; i<=n-1; i++) {
        t[i] +=  i+1;
        if (day < t[i]) {
            day = t[i];
        }
    }

    cout << day+1;

    return 0;
}
