// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int inf = 1e9;
int n;
int a[100005];
int f[100005][15]; //f[i][j]表示前i个以j为结尾最少删除多少个形成接龙
int fst (int a) {
    while (a>=10) a /= 10;
    return a;
}
int lst (int a) {
    return a %= 10;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=9;j++) f[i][j] = inf;
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=9;j++) {
            if (lst (a[i]) == j) f[i][j] = min (f[i-1][j] + 1, f[i-1][fst(a[i])]);
            else f[i][j] = f[i-1][j] + 1;
        }
    }
    int ans = inf;
    for (int i=0;i<=9;i++) ans = min(ans, f[n][i]);
    cout << ans << endl;
}