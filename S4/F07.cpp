// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int need[505], value[505];
int f[100005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> need[i] >> value[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (need[i] > j) continue;
            f[j] = max(f[j], f[j-need[i]] + value[i]);
        }
    }
    cout << f[m];
}