#include <stdio.h>
#include <string.h>

/*
Alphabet

A string of lowercase letters is called alphabetical if some of the letters can be deleted so that the only letters that
remain are the letters from 'a' to 'z' in order. Given a string s, determine the minimum number of letters to
add anywhere in the string to make it alphabetical.

Input
Each input will consist of a single test case. Note that your program may be run multiple times on different inputs.
The only line of input contains a string s (1<=|s|<=50) which contains only lowercase letters.

Output
Output a single integer, which is the smallest number of letters needed to add to s to make it alphabetical.

Sample Input 1	            Sample Output 1
xyzabcdefghijklmnopqrstuvw  3

Sample Input 2	            Sample Output 2
aiemckgobjfndlhp            20
*/

using namespace std;

int main() {
    char s[60];
    scanf("%s", s);

    int len = strlen(s);
    int a[len], maxlen = len==1? 1: 0;
    int i, j;

    a[0] = 1;
    for (i=1; i<len; i++) {
        a[i] = 1;
        for (j=i-1; j>=0; j--) {
            if (s[j]<s[i] && a[j]+1>a[i]) {
                a[i] = a[j] + 1;
            }
        }
        if (maxlen < a[i]) {
            maxlen = a[i];
        }
    }

    printf("%d", 26-maxlen);

    return 0;
}
