#include <stdio.h>
#include <string.h>

using namespace std;

/*
I've Been Everywhere, Man

Alice travels a lot for her work. Each time she travels, she visits a single city before returning home.
Someone recently asked her "how many different cities have you visited for work?" Thankfully Alice has kept a log of
her trips. Help Alice figure out the number of cities she has visited at least once.

Input
The first line of input contains a single positive integer T<=50 indicating the number of test cases.
The first line of each test case also contains a single positive integer n indicating the number of work trips
Alice has taken so far. The following n lines describe these trips. The i^th such line simply contains the name of
the city Alice visited on her i^th trip.

Alice's work only sends her to cities with simple names: city names only contain lowercase letters,
have at least one letter, and do not contain spaces.

The number of trips is at most 100 and no city name contains more than 20 characters.

Output
For each test case, simply output a single line containing a single integer that is the number of distinct cities that Alice has visited on her work trips.

Sample Input 1	Sample Output 1
2               4
7               1
saskatoon
toronto
winnipeg
toronto
vancouver
saskatoon
toronto
3
edmonton
edmonton
edmonton
*/

char a[100][25];
char s[25];
int n, t, i, j, k, c;

int main() {
    scanf("%d", &t);
    for (i=1; i<=t; i++) {
        c = 0;
        scanf("%d", &n);

        for (j=1; j<=n; j++) {
            fflush(stdin);
            scanf("%s", s);

            if (j>1) {
                for (k=0; k<c; k++) {
                    if (strcmp(a[k], s)==0) {
                        break;
                    }
                }
                if (k == c) {
                    strcpy(a[c], s);
                    c++;
                }
            } else {
                strcpy(a[c], s);
                c++;
            }
        }

        if (i>1) {
            printf("\n");
        }
        printf("%d", c);
    }

    return 0;
}
