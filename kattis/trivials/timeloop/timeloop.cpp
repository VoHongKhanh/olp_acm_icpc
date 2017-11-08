#include <iostream>

using namespace std;

/*
Stuck In A Time Loop

Last night when you went to sleep, you had a strange feeling that you may see the same day again.
And your strange feeling came to be when you woke up, everyone seemed to think that it was yesterday morning!
The same strange feeling came back in the evening.

When this pattern continued for days, you looked for help from a time wizard.
The wizard says he can break you out of the time loop, but you must chant his spell.
The wizard gives you a magic number, and you must count up to that number, starting at 11, saying "Abracadabra" each time.

Input
Input consists of a single integer N (1<=N<=100).

Output
Output the entire wizard's spell by counting from 1 to N, giving one number and "Abracadabra" per line.

Sample Input 1	Sample Output 1
5               1 Abracadabra
                2 Abracadabra
                3 Abracadabra
                4 Abracadabra
                5 Abracadabra

Sample Input 2	Sample Output 2
10              1 Abracadabra
                2 Abracadabra
                3 Abracadabra
                4 Abracadabra
                5 Abracadabra
                6 Abracadabra
                7 Abracadabra
                8 Abracadabra
                9 Abracadabra
                10 Abracadabra
*/

int n, i;

int main() {
    cin >> n;

    for (i=1; i<=n-1; i++) {
        cout << i << " Abracadabra" << endl;
    }
    cout << i << " Abracadabra";

    return 0;
}
