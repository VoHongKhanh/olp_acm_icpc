#include <iostream>

using namespace std;

/*
DRM Messages

DRM Encryption is a new kind of encryption. Given an encrypted string (which we'll call a DRM message),
the decryption process involves three steps: Divide, Rotate and Merge. This process is described in
the following example with the DRM message "EWPGAJRB":

Divide – First, divide the message in half to "EWPG" and "AJRB".
Rotate – For each half, calculate its rotation value by summing up the values of each character (A=0,B=1,…,Z=25).
         The rotation value of "EWPG" is 4+22+15+6=47. Rotate each character in "EWPG" 47 positions forward
         (wrapping from Z to A when necessary) to obtain the new string "ZRKB". Following the same process on "AJRB"
         results in "BKSC".
Merge  – The last step is to combine these new strings ("ZRKB" and "BKSC") by rotating each character in
         the first string by the value of the corresponding character in the second string. For the first position,
         rotating 'Z' by 'B' means moving it forward 1 character, which wraps it around to 'A'. Continuing this process
         for every character results in the final decrypted message, "ABCD".

Input
The input contains a single DRM message to be decrypted. All characters in the string are uppercase letters and the
string's length is even and <=15000.

Output
Display the decrypted DRM message.

Sample Input 1	                Sample Output 1
EWPGAJRB                        ABCD

Sample Input 2	                Sample Output 2
UEQBJPJCBUDGBNKCAHXCVERXUCVK    ACMECNACONTEST
*/

string s;
long l, l2, i, j, c1, c2;
char a[7500], b[7500];

char rotator(char c, long step) {
    long n = 'Z' - 'A' + 1;
    long r = (c - 'A' + step) % n;
    return (char)('A' + r);
}

int main() {
    cin >> s;

    l = s.length();
    l2 = l/2;
    c1 = 0;
    c2 = 0;
    for (i=0,j=l2; i<=l2-1; i++,j++) {
        a[i] = s.at(i);
        b[j-l2] = s.at(j);

        c1 += a[i] - 'A';
        c2 += b[j-l2] - 'A';
    }

    for (i=0; i<=l2-1; i++) {
        a[i] = rotator(a[i], c1);
        b[i] = rotator(b[i], c2);
    }

    for (i=0; i<=l2-1; i++) {
        a[i] = rotator(a[i], b[i] - 'A');
    }

    cout << a << endl;

    return 0;
}
