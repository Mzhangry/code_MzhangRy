// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int p[65], v[65], q[65];
vector<int> a[65];
int cnt = 0;
int f[32500];
int main() {
    int n, m;
    cin >> m >> n;
    for (int i=1;i<=n;i++) cin >> v[i] >> p[i] >> q[i];
    for (int i=1;i<=n;i++) if (q[i] != 0) a[q[i]].push_back(i);
    for (int i=1;i<=n;i++) {
        if (q[i] != 0) continue;
        for (int j=m;j>0;j--) {
            if (v[i] <= j) f[j] = max(f[j], f[j-v[i]] + v[i]*p[i]);
            if (a[i].size() >= 1 && v[i] + v[a[i][0]] <= j) f[j] = max(f[j], f[j-v[i]-v[a[i][0]]] + v[i]*p[i] + v[a[i][0]]*p[a[i][0]]);
            if (a[i].size() == 2 && v[i] + v[a[i][1]] <= j) f[j] = max(f[j], f[j-v[i]-v[a[i][1]]] + v[i]*p[i] + v[a[i][1]]*p[a[i][1]]);
            if (a[i].size() == 2 && v[i] + v[a[i][0]] + v[a[i][1]] <= j) f[j] = max(f[j], f[j-v[i]-v[a[i][0]]-v[a[i][1]]] + v[i]*p[i] + v[a[i][1]]*p[a[i][1]] + v[a[i][0]]*p[a[i][0]]);
        }
    }
    cout << f[m];
}