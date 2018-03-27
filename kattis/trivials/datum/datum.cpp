#include <stdio.h>
using namespace std;

/*
Datum

Write a program that, given a date in 2009, determines the day of week on that date.

Input
The first line contains two positive integers D (day) and M (month) separated by a space. The numbers will be a valid date in 2009.

Output
Output the day of the week on day D of month M in 2009. The output should be one of the words "Monday", "Tuesday", "Wednesday", "Thursday",
"Friday", "Saturday" or "Sunday".

Sample Input 1	  Sample Output 1
1 1               Thursday

Sample Input 2	  Sample Output 2
17 1              Saturday

Sample Input 3	  Sample Output 3
25 9              Friday
*/

int main() {
	int months[] = { 0,31,59,90,120,151,181,212,243,273,304,334};
	int D, M;
	
	scanf("%d%d", &D, &M);
	switch ((D + months[M-1]) % 7) {
		case 0: printf("Wednesday"); break;
		case 1: printf("Thursday"); break;
		case 2: printf("Friday"); break;
		case 3: printf("Saturday"); break;
		case 4: printf("Sunday"); break;
		case 5: printf("Monday"); break;
		case 6: printf("Tuesday"); break;
	}
	return 0;
}
