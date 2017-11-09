#include <iostream>

using namespace std;

/*
Bela

Young Mirko is a smart, but mischievous boy who often wanders around parks looking for new ideas. This time he's come
across pensioners playing the card game Belote. They've invited him to help them determine the total number of points
in a game.

Each card can be uniquely determined by its number and suit. A set of four cards is called a hand. At the beginning of
a game one suit that "trumps" any other is chosen, and it is called the dominant suit. The number of points in a game
is equal to the sum of values of each card from each hand in the game. Mirko has noticed that the pensioners have
played N hands and that suit B was the dominant suit.

The value of each card depends on its number and whether its suit is dominant, and is given in Table 1.
    A	11	11
    K	 4	 4
    Q	 3	 3
    J	20	 2
    T	10	10
    9	14	 0
    8	 0	 0
    7	 0	 0
    Table 1: Scores

Write a program that will determine and output the number of points in the game.

Input
The first line contains the number of hands N (1<=N<=100) and the value of suit B (S, H, D, C) from the task.
Each of the following 4N lines contains the description of a card (the first character is the number of
the i-th card (A, K, Q, J, T, 9, 8, 7), and the second is the suit (S, H, D, C)).

Output
The first and only line of output must contain the number of points from the task.

Sample Input 1	Sample Output 1
2 S             60
TH
9C
KS
QS
JS
TD
AD
JH

Sample Input 2	Sample Output 2
4 H             92
AH
KH
QH
JH
TH
9H
8H
7H
AS
KS
QS
JS
TS
9S
8S
7S
*/

int d[8], nd[8];

int getIndex(string c) {
    if (c == "A") {
        return 0;
    } else if (c == "K") {
        return 1;
    } else if (c == "Q") {
        return 2;
    } else if (c == "J") {
        return 3;
    } else if (c == "T") {
        return 4;
    } else if (c == "9") {
        return 5;
    } else if (c == "8") {
        return 6;
    } else if (c == "7") {
        return 7;
    }
}

void khoitao() {
    d[getIndex("A")] = 11;
    d[getIndex("K")] = 4;
    d[getIndex("Q")] = 3;
    d[getIndex("J")] = 20;
    d[getIndex("T")] = 10;
    d[getIndex("9")] = 14;
    d[getIndex("8")] = 0;
    d[getIndex("7")] = 0;

    nd[getIndex("A")] = 11;
    nd[getIndex("K")] = 4;
    nd[getIndex("Q")] = 3;
    nd[getIndex("J")] = 2;
    nd[getIndex("T")] = 10;
    nd[getIndex("9")] = 0;
    nd[getIndex("8")] = 0;
    nd[getIndex("7")] = 0;
}

int n, i, sum;
string b, s, v, t;

int main() {
    khoitao();

    cin >> n;

    cin.ignore();
    cin >> b;

    for (sum=0,i=1; i<=4*n; i++) {
        cin.ignore();
        cin >> s;
        v = s.substr(0,1);
        t = s.substr(1,1);
        sum += t==b? d[getIndex(v)]: nd[getIndex(v)];
    }

    cout << sum;

    return 0;
}
