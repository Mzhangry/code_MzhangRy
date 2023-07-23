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

int h, w, n;
bool e[3005][3005];
int f[3005][3005];
int main() {
    cin >> h >> w >> n;
    for (int i=1;i<=n;i++) {
        int a, b; cin >> a >> b;
        e[a][b] = true; //黑色
    }
    // 判断图中有多少个正方形子矩阵中不含黑色
    ll ans = 0;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            if (!e[i][j]) {
                f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
                ans += f[i][j];
            }
        }
    }
    cout << ans << endl;
}