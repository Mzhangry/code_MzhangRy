// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[25][25];
int m, n;
int main() {
    cin >> m >> n;
    for (int i=1;i<=m;i++) a[i][1] = 1;
    for (int i=1;i<=n;i++) a[1][i] = 1;
    for (int i=2;i<=m;i++) {
        for (int j=2;j<=n;j++) {
            a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
    cout << a[m][n];
}