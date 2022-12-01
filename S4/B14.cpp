// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105][105];
int s[105]; //以i为结尾的最大字段和
int f[105]; //纵向阶段和
int n, ans = -250;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int k=1;k<=n;k++) {
            f[k] = 0;
        }
        for (int t=i;t<=n;t++) {
            for (int k=1;k<=n;k++) s[k] = -250;
            for (int j=1;j<=n;j++) { // 计算纵向阶段和
                f[j] = f[j] + a[t][j];
            }
            for (int j=1;j<=n;j++) { // 计算以j为结尾的最大字段和
                s[j] = max(s[j-1]+f[j], f[j]);
            }
            int mx = -250;
            for (int j=1;j<=n;j++) { // 计算最大字段和
                mx = max(mx, s[j]);
            }
            ans = max(ans, mx);
        }
    }
    cout << ans;
}