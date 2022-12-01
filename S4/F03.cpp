// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int v[35];
bool f[35][20005];
int main() {
    int m, n;
    f[0][0] = true;
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> v[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            f[i][j] = f[i-1][j] | (v[i] <= j) & f[i-1][j-v[i]];
        }
    }
    for (int i=m;i>=0;i--) {
        if (f[n][i]) {
            cout << m-i;
            return 0;
        }
    }
}