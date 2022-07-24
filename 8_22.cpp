// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int a[45][45];
int main() {
    int n;
    cin >> n;
    n = 2*n-1;
    int x = 0, y = n/2;
    a[0][n/2] = 1;
    for (int i=2;i<=n*n;i++) {
        if (x == 0 && y == n-1) {
            a[x+1][y] = i;
            x = x+1;
        } else if (x == 0) {
            a[n-1][y+1] = i;
            x = n-1;
            y = y+1;
        } else if (y == n-1) {
            a[x-1][0] = i;
            x = x-1;
            y = 0;
        } else {
            if (a[x-1][y+1] != 0) {
                a[x+1][y] = i;
                x = x+1;
            } else {
                a[x-1][y+1] = i;
                x = x-1;
                y = y+1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}