// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int t[1005], w[1005], v[1005];
vector<int> a[1005];
int f[1005];
int main() {
    int n, m;
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> t[i] >> w[i] >> v[i];
    for (int i=1;i<=n;i++) a[t[i]].push_back(i);
    for (int i=1;i<=n;i++) {
        for (int j=m;j>0;j--) {
            for (int k=0;k<a[i].size();k++) {
                if (j < w[a[i][k]]) continue;
                f[j] = max(f[j], f[j-w[a[i][k]]] + v[a[i][k]]);
            }
        }
    }
    cout << f[m];
}