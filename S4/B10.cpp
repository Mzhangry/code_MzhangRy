// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char a[1010][1010];
int f[1010][1010];
int n, m;
int main() {
    int ans = 0;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] == '1') {
                f[i][j] = f[i][j-1] + 1;
            } else {
                f[i][j] = 0;
            }
            if (f[i][j] > ans) ans = f[i][j];
        }
    }
    cout << ans << endl;
}