#include <iostream>

/*
Good Morning!

Good morning! This is your 5am wake-up call! A partly cloudy day is expected with light rain coming afternoon…
You have just woken up. You desperately need coffee… and… more coffee… and some cereal. And your clothes. And coffee.
To prepare warm cereal, you put some milk into a microwave, trying to heat it for k seconds. You must enter k on the microwave keyboard:
    .-------------. .-------------.
    | ..| ..| ..| | | ..+ ..| ..| |
    | .1| .2| .3| | | .1+ .2| .3| |
    | __| __| __| | | +*+ __| __| |
    | ..| ..| ..| | | .*+ ..| ..| |
    | .4| .5| .6| | | .4+ .5| .6| |
    | __| __| __| | | +*+ __| __| |
    | ..| ..| ..| | | .*+ ..+ ..| |
    | .7| .8| .9| | | .7***8+ .9| |
    | __| __| __| | | +++ +*+ __| |
    |     ..|     | |     .*+     |
    |     .0|     | |     .0+     |
    |     __|     | |     +++     |
    ._____________. ._____________.
        Figure 1: Keyboard layout
As you still haven't had your coffee, your hand (along with eyes and brain) keeps falling down. You are only able to enter
a number if your hand would only move downwards and/or to the right. You cannot go back left, nor move your hand up,
though you can press the same key again. And again... and again...
For example, you can enter the number 180 or 49, but not 98 or 132. Enter a number that is as close to k as possible.
If there are two solutions, enter any one of them. You are too sleepy to actually care. And you need coffee.

Input
The first line of input contains the number of test cases T (1<=T<=200). The descriptions of the test cases follow:
Each test case consists of one line containing an integer k (1<=k<=200).

Output
For each test case, output a number that is closest to k which can be entered on the keyboard.

Sample Input 1	Sample Output 1
3               180
180             80
83              133
132
*/

using namespace std;

int board[10][10] = {
    {1,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,0,1,1},
    {0,0,0,1,0,0,1,0,0,1},
    {1,0,0,0,1,1,1,1,1,1},
    {1,0,0,0,0,1,1,0,1,1},
    {0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,1,1},
    {1,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,0,0,0,1}
};


int isAccept(int n) {
    if (n < 10) return 1;
    else if (n < 100) return board[n/10][n%10];
    else if (n < 1000) return board[n/100][(n/10)%10] && board[(n/10)%10][n%10];
    else return 0;
}

int main() {
    int T, k, i;

    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> k;

        if (isAccept(k)) {
            cout << k << endl;
        } else {
            i = 1;
            while (1) {
                if (isAccept(k+i)) {
                    cout << k+i << endl;
                    break;
                } else if (isAccept(k-i)) {
                    cout << k-i << endl;
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}
