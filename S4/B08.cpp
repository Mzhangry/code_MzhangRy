// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char a[1005][1005];
int f[1005][1005];
int ans[1000];
int main() {
    int m, n;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] == '*') f[i][j] = 1;
        }
    }
    int maxc = (min(n,m)+1)/2;
    for (int t=2;t<=maxc;t++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (a[i][j]=='*' && f[i-1][j]>=t-1 && f[i][j-1]>=t-1 && f[i+1][j]>=t-1 && f[i][j+1]>=t-1) 
                    f[i][j] = t;
            }
        }
    }
    for (int t=1;t<=maxc;t++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (f[i][j]>=t) ans[t]++;
            }
        }
    }
    for (int i=1;i<=maxc;i++) {
        if (ans[i]) cout << i << ' ' << ans[i] << endl;
    }
}