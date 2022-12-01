// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[15][15];
int main() {
    int t, m, n;
    a[1][1] = 1;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i=2;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                a[i][j] = a[i-1][j-1];
                if (i>j) a[i][j] += a[i-j][j];
            }
        }
        int ans = 0;
        for (int i=1;i<=n;i++) ans += a[m][i];
        cout << ans << endl;
    }
}