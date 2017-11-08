#include <iostream>

using namespace std;

/*
FizzBuzz

According to Wikipedia, FizzBuzz is a group word game for children to teach them about division. This may or may not be true, 
but this question is generally used to torture screen young computer science graduates during programming interviews.

Basically, this is how it works: you print the integers from 1 to N, replacing any of them divisible by X with Fizz or, 
if they are divisible by Y, with Buzz. If the number is divisible by both X and Y, you print FizzBuzz instead.

Check the samples for further clarification.

Input
Input file will contain a single test case. Each test case will contain three integers on a single line, X, Y and N (1<=X<Y<=N<=100).

Output
Print integers from 1 to N in order, each on its own line, replacing the ones divisible by X with Fizz, the ones 
divisible by Y with Buzz and ones divisible by both X and Y with FizzBuzz.

Sample Input 1	Sample Output 1
2 3 7           1
                Fizz
                Buzz
                Fizz
                5
                FizzBuzz
                7
                
Sample Input 2	Sample Output 2
2 4 7           1
                Fizz
                3
                FizzBuzz
                5
                Fizz
                7
                
Sample Input 3	Sample Output 3
3 5 7           1
                2
                Fizz
                4
                Buzz
                Fizz
                7
*/

int main() {
    int x, y, n, i;

    cin >> x >> y >> n;

    for (i=1; i<=n; i++) {
        if (i > 1) {
            cout << endl;
        }
        if (i%x==0 && i%y==0) {
            cout << "FizzBuzz";
        } else if (i%x == 0) {
            cout << "Fizz";
        } else if (i%y == 0) {
            cout << "Buzz";
        } else {
            cout << i;
        }
    }

    return 0;
}
