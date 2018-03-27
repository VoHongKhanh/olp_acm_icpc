#include <stdio.h>
using namespace std;

/*
Yoda

A long, long time ago in a galaxy far, far away a big collision of integers is taking place right now. What happens when two integers 
collide? During collision, each digit of one number compares itself to the corresponding digit of the other number (the least significant 
digit with the other's least significant digit, and so on). The smaller digit “falls out” of the number containing it. Additionally, 
if the digits are the same, nothing happens. If a number doesn't consist of a corresponding digit, then we consider it to be zero. 
After all comparisons of corresponding digits, the leftover digits in the number come closer and create a new number. See Figure 1 for 
an example.
    +---+---+---+---+---+---+        +---+---+---+---+---+---+
    | 4 | 5 | 6 | 3 | 2 | 8 |  --->  | 4 |   | 6 | 3 | 2 | 8 |  --->  46328
    +---+---+---+---+---+---+        +---+---+---+---+---+---+
    | 2 | 8 | 4 | 3 | 1 | 5 |  --->  |   | 8 |   | 3 |   |   |  --->     83
    +---+---+---+---+---+---+        +---+---+---+---+---+---+
                  Figure 1: Collision example
Write a programme that will, for two given integers, determine their values after collision. If it happens that all the digits of 
one number fell out, then for that number output the message "YODA".

Input
The first line of input contains the integer N (1<=N<=109), one of the integers from the task. The second line of input contains 
the integer M (1<=N<=109), one of the integers from the task.

Output
The first line of output must contain the new value of the first given integer from the task. The second line of output must contain 
the new value of the second given integer from the task.

Sample Input 1	  Sample Output 1
300               0
500               500

Sample Input 2	  Sample Output 2
65743             673
9651              95

Sample Input 3	  Sample Output 3
2341              YODA
6785              6785
*/

int main() {
	int a, b, m=0, n=0, i, j, i1, j1, y1=0, y2=0;
	
	scanf("%d%d", &a, &b);
	
	i1 = 1;
	j1 = 1;
	while (a>0 || b>0) {
		i = a%10;
		j = b%10;
		
		if (i>j) {
			n = i1*i + n;
			i1 *= 10;
			y1 = 1;
		} else if (i<j) {
			m = j1*j + m;
			j1 *= 10;
			y2 = 1;
		} else {
			n = i1*i + n;
			m = j1*j + m;
			i1 *= 10;
			j1 *= 10;
			y1 = 1;
			y2 = 1;
		}
		a /= 10;
		b /= 10;
	}
	if (y1==0) {
		printf("YODA\n%d", m);
	} else if (y2==0) {
		printf("%d\nYODA", n);
	} else {
		printf("%d\n%d", n, m);
	}
	
	// your code goes here
	return 0;
}
