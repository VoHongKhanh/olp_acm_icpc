#include <iostream>
#include <string>

using namespace std;

/*
Guess the Number

I am thinking of a number between 1 and 1000, can you guess what number it is? Given a guess, I will tell you whether the guess is too low, 
too high, or correct. But I will only give you 10 guesses, so use them wisely!

Interaction
Your program should output guesses for the correct number, in the form of an integer between 1 and 1000 on a line on its own. 
After making each guess, you need to make sure to flush standard out.

After each guess, there will be a response to be read from standard in. This response is a line with one of the following three words:
  # "lower" if the number I am thinking of is lower than your guess
  # "higher" if the number I am thinking of is higher than your guess
  # "correct" if your guess is correct

After having guessed the right answer your program should exit. If you guess incorrectly 10 times, you won't get any more chances and 
your program will be terminated.
*/

int main() {
    int l = 1, r = 1000, m;
    string ans = "";
    
    while(ans.compare("correct") != 0){
        m = (r + l) / 2;
    
        cout << m << endl;
        cout << flush;
    
        cin >> ans;
        if(ans.compare("lower") == 0) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return 0;
}
