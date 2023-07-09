// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int tim[105], value[105];
int f[1005];
int main() {
    int t, m;
    cin >> t >> m;
    for (int i=1;i<=m;i++) cin >> tim[i] >> value[i];
    for (int i=1;i<=m;i++) {
        for (int j=t;j>=0;j--) {
            if (tim[i] > j) break;
            f[j] = max(f[j], f[j-tim[i]] + value[i]);
        }
    }
    cout << f[t];
}