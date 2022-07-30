// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int a[15][15];
int n;
int maxsum (int x, int y) {
    if (x == n) return a[x][y];
    return a[x][y] + max (maxsum(x+1, y), maxsum(x+1, y+1));
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            cin >> a[i][j];
        }
    }
    cout << maxsum (1, 1);
}