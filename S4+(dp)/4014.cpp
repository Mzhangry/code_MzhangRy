// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[105][105], dp[105][105];
const int minx = -1e5 - 10;
// f[i][j] 表示前i个花放在前j瓶，且第i个放在j瓶 的最大xx
int main() {
    int f, v;
    cin >> f >> v;
    for (int i=1;i<=f;i++) {
        for (int j=1;j<=v;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<=f;i++) {
        for (int j=i;j<=v;j++) {
            dp[i][j] = minx;
            for (int k=i-1;k<=j-1;k++) {
                dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i][j]);
            }
        }
    }
    int ans = minx, pos;
    for (int i=f;i<=v;i++) {
        if (dp[f][i] > ans) {
            ans = dp[f][i];
            pos = i;
        }
    }
    cout << ans << endl;

    vector<int> sch;
    for (int i=f;i>=1;i--) {
        sch.push_back(pos);
        for (int j=pos-1;j>=1;j--) {
            if (dp[i][pos] == dp[i-1][j] + a[i][pos]) {
                pos = j;
                break;
            }
        }
    }
    for (int i=sch.size()-1;i>=0;i--) cout << sch[i] << ' ';
    cout << endl;
}