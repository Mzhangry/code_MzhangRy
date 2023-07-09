// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[505], v[505];
int f[100005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=0;j--) {
            if (w[i] > j) break;
            f[j] = max(f[j], f[j-w[i]] + v[i]);
        }
    }
    cout << f[m];
}