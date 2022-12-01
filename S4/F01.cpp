// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105];
bool f[105][10005];
int main() {
    int n;
    f[0][0] = 1;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=10000;j++) {
            f[i][j] = f[i-1][j];
            if (j-a[i] >= 0 && f[i-1][j-a[i]]) f[i][j] = true;
        }
    }
    int ans = 0;
    for (int i=1;i<=10000;i++) {
        if (f[n][i]) ans++;
    }
    cout << ans;
}