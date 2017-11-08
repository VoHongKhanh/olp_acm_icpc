#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Bank Queue

Oliver is a manager of a bank near KTH and wants to close soon. There are many people standing in the queue wanting to
put cash into their accounts after they heard that the bank increased the interest rates by 42% (from 0.01% per year to 0.0142% per year).

However, there are too many people and only one counter is open which can serve one person per minute.
Greedy as Oliver is, he would like to select some people in the queue, so that the total amount of cash stored
by these people is as big as possible and that money then can work for the bank overnight.

There is a problem, though. Some people don't have the time to wait until the bank closes because they have to
run somewhere else, so they have to be served before a certain time, after which they just leave.
Oliver also turned off the infrared door sensor outside the bank, so that no more people can enter,
because it's already too crowded in the hall.

Task
Help Oliver calculate how much cash he can get from the people currently standing in the queue before the bank closes by serving at most one person per minute.

Input
The first line of input contains two integers N (1<=N<=10000) and T (1<=T<=47), the number of people in the queue and
the time in minutes until Oliver closes the bank. Then follow N lines, each with 2 integers c_i and t_i,
denoting the amount of cash in Swedish crowns person i has and the time in minutes from now after which person i
leaves if not served. Note that it takes one minute to serve a person and you must begin serving a person at time t_i
at the latest. You can assume that 1<=c_i<=100000 and 0<=t_i<=T.

Output
Output one line with the maximum amount of money you can get from the people in the queue before the bank closes.

Sample Input 1	Sample Output 1
4 4             4200
1000 1
2000 2
500 2
1200 0

Sample Input 2	Sample Output 2
3 4             3000
1000 0
2000 1
500 1

Sample Input 3	Sample Output 3
6 4             5700
1000 3
1500 1
2000 3
500 1
200 4
1000 0
*/

int n, t, ti, ci, i, j, k;
int l[47];
int m[47];
int v[47][10000];
long c;

int comparator(const void* a, const void* b) {
    return *((int*)b) - *((int*)a);
}

int main() {
    cin >> n >> t;

    for(i=0; i<=t-1; i++) {
        l[i] = 0;
        m[i] = 0;
        for(j=0; j<=n-1; j++) {
            v[i][j] = 0;
        }
    }

    for(i=0; i<=n-1; i++) {
        cin >> ci >> ti;

        v[ti][l[ti]] = ci;
        l[ti]++;
    }

    for (i=0; i<=t; i++) {
        if (l[i] > 1) {
            qsort(v[i], l[i], sizeof(int), comparator);
        }
    }

    c = 0;
    for (i=t; i>=0; i--) { //--- do thoi diem bat dau tinh tien
        int max_value = 0;
        int max_index = -1;
        for (j=i; j<=t; j++) { //--- do cac khach hang van con thoi gian de tinh tien
            if (v[j][m[j]] > max_value) {
                max_value = v[j][m[j]];
                max_index = j;
            }
        }

        if (max_index != -1) {
            c += max_value;
            m[max_index]++;
        }
    }

    cout << c;

    return 0;
}
