#include <iostream>
#include <iomanip>

using namespace std;

/*
Grass Seed Inc.

Many years ago after another unfruitful day in Cubicle Land, banging her head against yet another cutting edge, 
marketing buzzword-filled JavaScript framework, Janice the engineer looked out of the window and decided that time 
was ripe for a change.

So swapping her keyboard and mouse for a fork and a spade, she started her own gardening company.

After years of hard outdoor work Janice now has biceps like Van Damme and owns the premiere landscaping company in 
the whole of the South West, and has just been lucky enough to broker a large contract to sow lawns for landed gentry.

Each contract details the size of the lawns that need to be seeded, and the cost of seed per square metre. 
How much do you need to spend on seed?

Input
# One line containing a real number C (0<C<=100), the cost of seed to sow one square metre of lawn.
# One line containing an integer L (0<L<=100), the number of lawns to sow.
# L lines, each containing two positive real numbers: w_i (0<=w_i<=100), the width of the lawn, and l_i (0<=l_i<=100), 
  the length of the lawn.
All real numbers are given with at most 8 decimals after the decimal point.

Output
# One line containing a real number: the cost to sow all of the lawns.
All output must be accurate to an absolute or relative error of at most 10^−6.

Sample Input 1	Sample Output 1
2               112.0000000
3
2 3
4 5
5 6

Sample Input 2	Sample Output 2
0.75            16.6796025
2
2 3.333
3.41 4.567
*/

double c;
long double wi, li, s;
int l, i;

int main() {
    cin >> c >> l;

    s = 0;
    for (i=1; i<=l; i++) {
        cin >> wi >> li;
        s += wi*li;
    }
    s *= c;

    cout << std::fixed << setprecision(6) << s;

    return 0;
}
