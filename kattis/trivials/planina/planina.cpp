#include <iostream>

using namespace std;

/*
Planina

Mirko and Slavko are filming a movie adaptation of the popular SF novel "Chicks in space 13". The script requires them to
present a lot of different worlds so they decided to film the entire movie in front of a green screen and add CGI backgrounds later.
Mirko heard that the best way to generate artificial terrain is to use midpoint displacement algorithm.

To start the algorithm, Mirko selects 4 points forming a perfect square. He then performs the following steps:
1. On each side of the square, he adds a new point in the exact middle of the side. The height of this new point is
the average height of the two points on that side.
2. In the exact center of the square he adds a new point whose height is the average height of all 44 square vertices,
plus a small random value.

After those two steps are performed, he now has 4 new squares. He performs the same steps on the newly created squares
again and again until he is pleased with the results.

*       *    o   *   o    o * o * o
                          * * * * *
             *   *   *    o * o * o
                          * * * * *
*       *    o   *   o    o * o * o

*/

int main() {
    int i, n;
    long long int f = 2;
    cin >> n;
    for (i=1; i<=n; i++) {
        f += f-1;
    }
    f *= f;
    cout << f;

    return 0;
}
