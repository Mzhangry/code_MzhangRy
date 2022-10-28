// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char a[1505][1505];
int f[1505][1505][4]; //0up 1down 2left 3right
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j] == '1') {
                f[i][j][0] = f[i][j-1][0] + 1;
                f[i][j][2] = f[i-1][j][2] + 1;
            } else f[i][j][0] = 0;
        }
    }
    for (int i=n;i>=1;i--) {
        for (int j=n;j>=1;j--) {
            if (a[i][j] == '1') {
                f[i][j][1] = f[i][j+1][1] + 1;
                f[i][j][3] = f[i+1][j][3] + 1;
            } else f[i][j][0] = 0;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            ans = max (ans, min(min(f[i][j][0],f[i][j][1]), min(f[i][j][2], f[i][j][3])) - 1);
        }
    }
    cout << ans;
}