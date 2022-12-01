// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105][105][55]; // a[i][j][k] 表k个田恰好种iA和jB
int mod = 998244353;
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    int dx[8] = {0, 0, 1, 1, 1, 2, 2, 2},
        dy[8] = {1, 2, 0, 1, 2, 0, 1, 2};
    for (int i=0;i<8;i++) {
        a[dx[i]][dy[i]][1] = 1;
    }
    for (int i=0;i<=x;i++) {
        for (int j=0;j<=y;j++) {
            for (int k=2;k<=n;k++) {
                for (int d=0;d<8;d++) {
                    int p = i-dx[d], q = j-dy[d];
                    if (p<0 || q<0) continue;
                    a[i][j][k] = (a[i][j][k] + a[p][q][k-1]) % mod;
                }
            }
        }
    }
    long long ans = 0;
    for (int i=0;i<=x;i++) {
        for (int j=0;j<=y;j++) {
            ans = (ans + a[i][j][n]) % mod;
        }
    }
    cout << ans;
    return 0;
}