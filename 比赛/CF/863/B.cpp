// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t, n;
int floor (int x, int y) {
    int d1 = x-1, d2 = y-1, d3 = n-x, d4 = n-y;
    return max(max(d1, d2), max(d3, d4)) + 1;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << abs(floor(x1, y1) - floor(x2, y2)) << endl;
    }
    return 0;
}