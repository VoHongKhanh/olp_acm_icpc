#include <iostream>
#include <stdlib.h>

using namespace std;

/*
Bus Numbers

Your favourite public transport company LS (we cannot use their real name here, so we permuted the letters) wants to
change signs on all bus stops. Some bus stops have quite a few buses that stop there and listing all the buses takes space.
However, if for example buses 141, 142, 143 stop there, we can write 141-143 instead and this saves space. Note that just
for two buses this does not save space.

You are given a list of buses that stop at a bus stop. What is the shortest representation of this list?

Input
The first line of the input contains one integer N,1<=N<=1000, the number of buses that stop at a bus stop.
Then next line contains a list of N space separated integers between 1 and 1000, which denote the bus numbers.
All numbers are distinct.

Output
Print the shortest representation of the list of bus numbers. Use the format as in the example, separate numbers with
single spaces and output them in sorted order.

Sample Input 1	            Sample Output 1
6                           141-143 174 175 180
180 141 174 143 142 175
*/

int a[1000], n, i, s, e;

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    qsort (a, n, sizeof(int), compare);


    i = 0;
    while (i < n) {
        s = a[i];
        while(i+1<n && a[i]==a[i+1]-1) {
            i++;
        }

        e = a[i];
        if (s == e) {
            cout << s;
        } else if (s == e - 1) {
            cout << s << " " << e;
        } else {
            cout << s << "-" << e;
        }
        if (e < a[n-1]) {
            cout << " ";
        }
        i++;
    }
    return 0;
}
