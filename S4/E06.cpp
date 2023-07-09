// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int f[105][105];
int v[105];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<k;j++) {
            f[i][j] = -1;
        }
    }
    for (int i=1;i<=n;i++) cin >> v[i];
    f[0][0] = 0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<k;j++) {
            if (f[i-1][j] > -1) f[i][j] = f[i-1][j];
            if (f[i-1][(j+k-v[i]%k)%k] > -1) f[i][j] = max(f[i][j], (v[i] + (j+k-v[i]%k)%k)/k + f[i-1][(j+k-v[i]%k)%k]);
                                                                //   数量    1到i-1点余数    成组    1到i-1个的数量组
        }
    }
    if (f[n][0] == -1) cout << 0;
    else cout << f[n][0] * k;
}