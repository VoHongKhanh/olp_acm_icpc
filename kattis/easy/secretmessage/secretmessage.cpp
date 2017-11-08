#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
Secret Message

Jack and Jill developed a special encryption method, so they can enjoy conversations without worrying about eavesdroppers.
Here is how: let L be the length of the original message, and M be the smallest square number greater than or equal to L.
Add (M−L) asterisks to the message, giving a padded message with length M. Use the padded message to fill a table of size K×K,
where K^2=M. Fill the table in row-major order (top to bottom row, left to right column in each row).
Rotate the table 90 degrees clockwise. The encrypted message comes from reading the message in row-major order from
the rotated table, omitting any asterisks.

For example, given the original message 'iloveyouJack', the message length is L=12.
Thus the padded message is 'iloveyouJack****', with length M=16M=16. Below are the two tables before and after rotation.

i l o v
e y o u
J a c k
* * * *

* J e i
* a y l
* c o o
* k u v

Then we read the secret message as 'Jeiaylcookuv'.

Input
The first line of input is the number of original messages, 1<=N<=100. The following N lines each have a message to encrypt.
Each message contains only characters a–z (lower and upper case), and has length 1<=L<=10000.

Output
For each original message, output the secret message.

Sample Input 1	    Sample Output 1
2                   iteiloylloooJuv
iloveyoutooJill     OsoTvtnheiterseC
TheContestisOver
*/

int n, k, h, i, j;
string s, des;

int main(){
	cin >> n;

    for (h=0; h<n; h++){
        cin >> s;

        k = ceil(sqrt(s.size()));
        string temp (k*k - s.size(),'*');
        s.append(temp);

        des.clear();
        for (j=0; j<k; j++) {
            for (i=k-1; i>=0; i--) {
                if (s[k*i + j] != '*'){
                    des.push_back(s[k*i + j]);
                }
            }
        }
        cout << des << endl;
    }

	return 0;
}
