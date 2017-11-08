#include <iostream>

using namespace std;

/*
Cetvrta

Mirko needs to choose four points in the plane so that they form a rectangle with sides parallel to the axes. 
He has already chosen three points and is confident that he hasn't made a mistake, but is having trouble locating 
the last point. Help him.

Input
Each of the three points already chosen will be given on a separate line. All coordinates will be integers between 
1 and 1000.

Output
Output the coordinates of the fourth vertex of the rectangle.

Sample Input 1	Sample Output 1
5 5             7 7
5 7
7 5

Sample Input 2	Sample Output 2
30 20           30 10
10 10
10 20
*/

int main() {
    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    if (x1 == x2) {
        cout << x3;
    } else if (x1 == x3) {
        cout << x2;
    } else {
        cout << x1;
    }
    cout << " ";
    if (y1 == y2) {
        cout << y3;
    } else if (y1 == y3) {
        cout << y2;
    } else {
        cout << y1;
    }

    return 0;
}
