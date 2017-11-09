#include <stdio.h>

using namespace std;

/*
Death Knight Hero

There once was a champion of WoW
Arthasdk the name he was bestowed
He Death Gripped you to his side
His Chains of Ice stopped your stride
And Obliterates made you say "OWW!"

But one day our hero got puzzled
His Death Grip totally fizzled
In his darkest despair
He could barely hear
"OMG NOOB u Chains of Iced than u Death Gripped"

Input
You are given a recording of the abilities our hero used in his battles.

The first line of input will contain a single integer n (1<=n<=100), the number of battles our hero played.

Then follow n lines each with a sequence of k_i (1<=k_i<=1000) characters, each of which are either 'C', 'D' or 'O'.
These denote the sequence of abilities used by our hero in the ii-th battle. 'C' is Chains of Ice, 'D' is Death Grip
and 'O' is Obliterate.

Output
Output the number of battles our hero won, assuming he won each battle where he did not Chains of Ice immediately followed by Death Grip.

Sample Input 1	Sample Output 1
3               2
DCOOO
DODOCD
COD
*/

int n, i;
int won = n;
char s[1001];

int main() {
  scanf("%d", &n);

  while (n--) {
    scanf("%s\n", s);

    i = 0;
    while (s[++i]) {
      if (s[i - 1] == 'C' && s[i] == 'D') {
        won--;
        break;
      }
    }
  }
  printf("%d", won);
}
