// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105], g[10005];
int main() {
    int n, m;
    cin >> n >> m;
    g[0] = 0;
    for (int i=1;i<=n;i++) g[i] = -1;
    for (int i=0;i<m;i++) {
        cin >> a[i];
        g[a[i]] = 1;
    }
    for (int i=1;i<=n;i++) {
        if (g[i] != -1) continue;
        int ming = 100000;
        for (int j=0;j<m;j++) {
            if (i-a[j] < 0 || g[i-a[j]] == -1) continue;
            ming = min(ming, g[i-a[j]] + 1);
        }
        if (ming > 10000) g[i] = -1;
        else g[i] = ming;
    }
    cout << g[n];
}