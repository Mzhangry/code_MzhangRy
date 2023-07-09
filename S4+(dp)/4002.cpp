// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int s[505], w[505], l[505];
int f[505][505]; // 表示第i-n个怪用j个能量石能获得的最大经验
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> s[i] >> w[i] >> l[i];
    for (int i=n;i>=1;i--) {
        for (int j=m;j>=0;j--) {
            f[i][j] = f[i+1][j] + l[i];
            if (s[i] <= j) f[i][j] = max(f[i][j], f[i+1][j-s[i]] + w[i]);
        }
    }
    int j = m, mx = f[1][m];
    vector<int> ans;
    for (int i=1;i<=n;i++) {
        if (j-s[i] >= 0 && f[i+1][j-s[i]] == f[i][j] - w[i]) {
            ans.push_back(i);
            j = j-s[i];
        }
    }
    cout << mx << endl << ans.size() << endl;
    for (int i=0;i<ans.size();i++) cout << ans[i] << ' ';
}