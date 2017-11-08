#include <bits/stdc++.h>

using namespace std;

/*
Seven Wonders

Seven Wonders is a card drafting game in which players build structures to earn points. The player who ends with
the most points wins. One winning strategy is to focus on building scientific structures. There are three types of
scientific structure cards: Tablet ('T'), Compass ('C'), and Gear ('G'). For each type of cards, a player earns a number of
points that is equal to the squared number of that type of cards played. Additionally, for each set of three different
scientific cards, a player scores 7 points.

For example, if a player plays 3 Tablet cards, 2 Compass cards and 1 Gear card, she gets 3^2 + 2^2 + 1^2 + 7 = 21 points.

It might be tedious to calculate how many scientific points a player gets by the end of each game. Therefore,
you are here to help write a program for the calculation to save everyone's time.

Input
The input has a single string with no more than 5050 characters. The string contains only letters 'T', 'C' or 'G',
which denote the scientific cards a player has played in a Seven Wonders game.

Output
Output the number of scientific points the player earns.

Note
Seven Wonders was created by Antoine Bauza, and published by Repos Production. Antoine Bauza and Repos Production do not
endorse and have no involvement with the ProgNova contest.

Sample Input 1	Sample Output 1
TCGTTC          21

Sample Input 2	Sample Output 2
CCC             9

Sample Input 3	Sample Output 3
TTCCGG          26
*/

int main() {
	int t=0, c=0, g=0;
	long long int r=0;
	string s;

	cin >> s;

	for(int i=0; i<=s.length()-1; i++) {
		if(s[i] == 'T') {
            t++;
        } else if(s[i] == 'C') {
            c++;
        } else if(s[i] == 'G') {
            g++;
        }
	}
	r += (t*t + c*c + g*g);
	r += (min(g, min(t,c)))*7;
	cout << r;
	return 0;
}
