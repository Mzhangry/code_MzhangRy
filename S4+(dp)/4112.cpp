// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int v[2005];
long long f[2005][2005];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> v[i];
    for (int len = 1;len <=n;len++) {
        for (int st = 1;st <= n+1-len;st++) {
            int ed = st + len - 1;
            f[st][ed] = max (f[st+1][ed] + v[st]*(n-len+1), f[st][ed-1] + v[ed]*(n-len+1));
        }
    }
    cout << f[1][n];
}