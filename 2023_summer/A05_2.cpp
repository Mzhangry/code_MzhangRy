// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n; 
int a[500005];
bool vis[500005];
int c1, las;
bool dp (int i) {
    if (i == 0) { // 判别序列b是否合法
        int b1=0, b2=0;
        for (int j=1;j<=n;j++) {
            if (!vis[j] && b1 == 0) b1 = j;
            else if (!vis[j] && b2 == 0) {
                b2 = j; break;
            }
        }
        if (!b1 || !b2) return true;
        int c2 = a[b2] - a[b1];
        int d = b2;
        for (int j=b2+1;j<=n;j++) {
            if (!vis[j]) {
                // for (int i=1;i<=n;i++) if (vis[i]) cout << a[i] << ' ';
                // cout << endl;
                if (a[j] - a[d] != c2) return false;
                d = j;
            }
        }
        // for (int i=1;i<=n;i++) if (vis[i]) cout << a[i] << ' ';
        return true;
    }

    bool flag1 = false; 
    if (las - a[i] == c1) {
        vis[i] = true;
        int las2 = las;
        las = a[i];
        flag1 = dp(i-1);
        vis[i] = false;
        las = las2;
    }

    bool flag2 = dp(i-1);
    if (flag1 | flag2) return true;
    else return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        memset (vis, 0, sizeof(vis));
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        if (n == 1) {
            cout << "Yes" << endl;
            continue;
        }
        vis[n] = true;
        bool flag = false;
        for (int i=n-1;i>0;i--) { // 挑选a的倒数第二个
            c1 = a[n] - a[i];
            vis[i] = true;
            las = a[i]; // 上一个在子序列中
            if (dp(i-1)) {
                cout << "Yes" << endl;
                flag = true;
                break;
            }

            vis[i] = false;
        }
        if (!flag) cout << "No" << endl;
    }
}