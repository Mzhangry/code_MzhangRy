// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int p[105], t[105], k[105];
int f[550];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> p[i] >> t[i] >> k[i];
    for (int i=1;i<=n;i++) {
        if (k[i] == 0) k[i] = 500;
        for (int j=m;j>0;j--) {
            for (int q=1;q<=k[i] && q*t[i] <= j;q++) {
                f[j] = max(f[j], f[j-q*t[i]] + p[i]*q);
            }
        }
    }
    cout << f[m];
}