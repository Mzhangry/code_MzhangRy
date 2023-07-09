// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

char s[1600][1600];
int costr[1600], costc[1600];
int f[1600][1600];
int n;
int ans = 0;
void qingkongf () {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            f[i][j] = 1;
        }
    }
}
void solve() {
    qingkongf ();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (s[i][j] == 'R') {
                if (j+1 > n) ans += f[i][j] * costr[i];
                else f[i][j+1] += f[i][j];
            } else {
                if (i+1 > n) ans += f[i][j] * costc[j];
                else f[i+1][j] += f[i][j];
            }
        }
    }
    cout << ans << endl;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> s[i][j];
        }
        cin >> costr[i];
    }
    for (int i=1;i<=n;i++) cin >> costc[i];
    solve();
    int q;
    cin >> q;
    while (q--) {
        int i, j; cin >> i >> j;
        int x = i, y = j;
        while (x<=n && y<=n) { // 删除原来的增加
            if (s[x][y] == 'R') y++;
            else x++;
            f[x][y] -= f[i][j];
            if (x > n) ans -= costc[y] * f[i][j];
            else if (y > n) ans -= costr[x] * f[i][j];
        }
        if (s[i][j] == 'D')  s[i][j] = 'R';
        else s[i][j] = 'D';
        x = i; y = j;
        while (x<=n && y<=n) { // 新的增加
            if (s[x][y] == 'R') y++;
            else x++;
            f[x][y] += f[i][j];
            if (x > n) ans += costc[y] * f[i][j];
            else if (y > n) ans += costr[x] * f[i][j];
        }
        cout << ans << endl;
    }
}