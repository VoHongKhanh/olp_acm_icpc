#include <iostream>

using namespace std;

/*
Batter Up

While the Chicago Cubs were ecstatic with their 2016 World Series championship, they were eliminated from the playoffs
in 2017. Looking ahead to 2018 they are beginning to embrace the more data-driven analysis of player's values known as Sabermetrics.

For example, a player's batting average is calculated by dividing the total number of base hits by
the total number of official at-bats. One limitation of using the batting average to evaluate players is that
it treats all hits equally, rather than taking into account doubles, triples or home runs.
For this reason, analysts often prefer to consider what is known as the slugging percentage,
which distinguishes between different hit outcomes. To calculate the slugging percentage,
the total number of bases of all hits is divided by the total numbers of time at bat, that did not result in walks, or at-bats.

More specifically, an at-bat can earn 0, 1, 2, 3 or 4 bases (these are referred to as official at-bats).
Furthermore, some at-bats, such as those that result in a base-on-balls (i.e., a "walk") are not considered in either
the player's batting average or slugging percentage.

For example, if a player hits a triple (3 bases), strikes out (0 bases), and hits a double (2 bases),
their slugging percentage would be (3+0+2)/3 == 1.6667. If a player hits a single (1 base), walks,
and hits a home run (4 bases), the slugging level would be (1+4)/2=2.5. Notice that in this case, the denominator
is two, not three, because the walk does not count towards the slugging percentage.

Input
The input is composed of two lines. The first line contains a single positive integer n (1<=n<=100)
that specifies the number of at-bats. The second line contains n integers, separated by spaces,
each describing one of those at-bats. Strike-outs, singles, doubles, triples, and home runs are represented
as 0, 1, 2, 3, 4, respectively. Walks are represented as -1. You may assume that there will always be at least
one official at-bat (i.e., at least one at-bat will not be a walk).

Output
Display the player's slugging percentage as a real number, accurate to within an absolute or relative error of 10^-3.
We recommend that you do not round the value that you calculate.

Sample Input 1	            Sample Output 1
3                           1.6666666666666667
3 0 2

Sample Input 2	            Sample Output 2
3                           2.5
1 -1 4

Sample Input 3	            Sample Output 3
11                          0.14285714285714285
-1 -1 -1 -1 0 0 0 0 0 0 1
*/

int n, v, c, i, s;

int main() {
    cin >> n;

    for(s=0, c=0, i=1; i<=n; i++) {
        cin >> v;
        if (v >= 0) {
            c++;
            s += v;
        }
    }
    cout.precision(4);
    cout << (long double)s/c;
    return 0;
}
