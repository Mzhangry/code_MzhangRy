// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
char c[1005][1005];
int f[1005][1005];
int ans[1005];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> c[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (c[i][j] == '*') f[i][j] = 1;
        }
    }
    for (int i=3;i<=n;i++) {
        for (int j=2;j<m;j++) {
            if (f[i][j]) 
                f[i][j] = min(min(f[i-2][j], f[i-1][j]), min(f[i-1][j-1], f[i-1][j+1])) + 1;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=1;k<=f[i][j];k++) {
                ans[k]++;
            }
        }
    }
    for (int i=1;;i++) {
        if (ans[i] == 0) break;
        cout << i << ' ' << ans[i] << endl;
    }
}