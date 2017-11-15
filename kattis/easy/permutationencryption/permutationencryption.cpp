#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

/*
Permutation Encryption

Working for the Texas Spy Agency, you are in charge of writing software for handling secure communications 
between your clients who wish to pass you messages without anyone else being able to read them. Therefore, 
you have been commissioned to write a program which takes messages and encrypts them according to a key that 
you have. The spy agency is not very technologically advanced, and everything has been done by hand until now, 
which is why you were hired. Thus, their codes are also fairly simple – they're just character permutations.

A permutation of length n, as you know, is a list of the numbers 1 through n but in some rearranged order. 
So "1 2 3" is a permutation of length 3, and so is "2 1 3", but "5 3 6 4 1 2" is a permutation of length 6. 
Notice that every number between 1 and n appears in the permutation.

A key is a permutation which is used to change the message. For instance, the key "1 2 3 4 5" is a permutation 
of length 5 which does absolutely nothing – an encrypted message and a decrypted message would be identical. 
The key "2 1" would reverse every two characters. So the phrase 'I like ice cream' would be encrypted 
as ' Iileki ecc erma'. The key "5 1 4 2 3" would encrypt the word 'howdy' as 'yhdow'.

As you might imagine, if the message is longer than the key, just keep applying the key to each set of 
n characters. One last example. If the key is "4 1 3 5 2 6", then n is 6, and we would encrypt the message 
"Four score and seven years ago" as (spaces, vertical bars, and single quotes are added for clarity):

index:      1 2 3 4 5 6|1 2 3 4 5 6|1 2 3 4 5 6|1 2 3 4 5 6|1 2 3 4 5 6|1 2 3 4 5 6
message:   'F o u r   s|c o r e   a|n d   s e v|e n   y e a|r s   a g o|.          '
key:        4 1 3 5 2 6|4 1 3 5 2 6|4 1 3 5 2 6|4 1 3 5 2 6|4 1 3 5 2 6|4 1 3 5 2 6
encrypted: 'r F u   o s|e c r   o a|s n   e d v|y e   e n a|a r   g s o|  .        '

Note from this example that if the message length is not a multiple of the key length, your program should pad 
the original message with extra spaces at the end so that the message length is a multiple of the key length.

Input
The input to your program is a list of up to 150 messages to encrypt. Each message has two lines (one for the key, 
one for the message content). The first line starts with an integer 1<=n<=20, the length of the key, followed by 
n integers which form the permutation. The second line contains the message content. Your program should encrypt 
everything on the second line, spaces and all. Input ends when n is zero.

Output
For each message, pad the input with spaces as necessary, encrypt the message with the key, and output 
the encrypted message. Include single quotes around the encrypted message.

Sample Input 1												Sample Output 1
1 1															'Four score and seven years ago'
Four score and seven years ago 								'uo rafhtre srbuohgf rohto  nhtsic noitentna n wen taoi,n'
2 2 1														'cnoeciev di nilbreyt na dddeciaet dt ohtep orpsotiino  '
our fathers brough forth on this continent a new nation,	' mltaatlh rece ea nr luaeedqta   .      '
5 1 3 2 5 4													
conceived in liberty and dedicated to the proposition		
10 5 10 8 1 3 6 4 7 2 9										
that all men are created equal.
0
*/

int main() {
    while(1) {
        int n;
        cin >> n;
        
        if (n == 0) {
        	break;
        }

        int a[n];
        for (int i = 0; i < n; i++) {
        	cin >> a[i];
        }

        std::string s;
        std::cin.ignore();
        std::getline(std::cin, s);
        size_t remainder = s.length() % n;
        if (remainder > 0) {
        	s.append(n - remainder, ' ');
        }

        size_t iterations = s.length() / n;
        cout << "'";
        for (int i = 0; i < iterations; i++) {
            for (int j = 0; j < n; j++) {
                cout << s[i * n  + a[j] - 1];
            }
        }
        cout << "'" << endl;
    }
    return 0;
}
