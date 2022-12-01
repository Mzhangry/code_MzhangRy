// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[25];
int f[25][1005];
int main() {
    int n, t;
    cin >> n >> t;
    for (int i=1;i<=n;i++) cin >> a[i];
    f[0][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=t;j++) {
            f[i][j] = f[i-1][j];
            if (j >= a[i]) f[i][j] += f[i-1][j-a[i]];
        }
    }
    cout << f[n][t];
}