// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int f[1005];
int p[4] = {10, 20, 50, 100};
int main() {
    f[0] = 1;
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    for (int i=0;i<4;i++) {
        for (int j=1;j<=n;j++) {
            if (p[i] > j) continue;
            f[j] = f[j] + f[j-p[i]];
        }
    }
    cout << f[n];
}