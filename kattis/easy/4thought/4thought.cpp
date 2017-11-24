#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
4 thought

Write a program which, given an integer n as input, will produce a mathematical expression whose solution is n.
The solution is restricted to using exactly four 4's and exactly three of the binary operations selected from the set
{*,+,-,/}. The number 4 is the ONLY number you can use. You are not allowed to concatenate fours to generate other
numbers, such as 44 or 444.

For example given n=0, a solution is 4*4-4*4=0. Given n=7, a solution is 4+4-4/4=7. Division is considered truncating integer
division, so that 1/4 is 0 (instead of 0.25). Assume the usual precedence of operations so that 4+4*4=20, not 32.
Not all integer inputs have solutions using four 4's with the aforementioned restrictions (consider n=11).

Hint: Using your forehead and some forethought should make an answer forthcoming. When in doubt use the fourth.

Input
Input begins with an integer 1<=m<=1000, indicating the number of test cases that follow. Each of the next m lines
contain exactly one integer value for n in the range -1000000<=n<=1000000.

Output
For each test case print one line of output containing either an equation using four 4's to reach the target number or
the phrase no solution. Print the equation following the format of the sample output; use spaces to separate the numbers
and symbols printed. If there is more than one such equation which evaluates to the target integer, print any one of them.

Sample Input 1	    Sample Output 1
5                   4 + 4 + 4 / 4 = 9
9                   4 * 4 - 4 * 4 = 0
0                   4 + 4 - 4 / 4 = 7
7                   no solution
11                  4 * 4 + 4 + 4 = 24
24
*/

unsigned int M, m, n, i, j, k, h;
map<int, string> result;
map<int, char> op;

int calculate(int a, int b, char op){
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return -1;
}

int main(){
    op[0] = '*';
    op[1] = '/';
    op[2] = '+';
    op[3] = '-';

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            for(k = 0; k < 4; k++){
                vector<int>  values;
                values.push_back(4);
                values.push_back(4);
                values.push_back(4);
                values.push_back(4);

                vector<char> operators;
                operators.push_back(op[i]);
                operators.push_back(op[j]);
                operators.push_back(op[k]);

                for(h = 0; h < operators.size(); h++){
                    if(operators[h] == '*' || operators[h] == '/'){
                        values[h] = calculate(values[h], values[h+1], operators[h]);
                        values.erase(values.begin() + h+1);
                        operators.erase(operators.begin() + h);
                        h--;
                    }
                }

                for(h = 0; h < operators.size(); h++){
                    values[h] = calculate(values[h], values[h+1], operators[h]);
                    values.erase(values.begin() + h+1);
                    operators.erase(operators.begin() + h);
                    h--;
                }

                result[values[0]] = "4 " + string(1,op[i]) + " 4 " + string(1,op[j]) + " 4 " + string(1,op[k]) + " 4 = ";
            }
        }
    }

    cin >> M;
    for (m=1; m<=M; m++) {
        cin >> n;
        if(result.find(n) != result.end()){
            cout << result[n] << n << endl;
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}
