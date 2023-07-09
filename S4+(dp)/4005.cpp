// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const long long mxll = 1e18; 
long long v[505], w[505];
long long f[250005];
int main() {
    int n;
    long long c;
    cin >> n >> c;

    for (int j=1;j<=250003;j++) {
        f[j] = mxll + 1;
    }
    
    for (int i=1;i<=n;i++) cin >> v[i] >> w[i];
    for (int i=1;i<=n;i++) {
        for (int j=n*500;j>=1;j--) {
            f[j] = min(f[j], f[j+1]);
            if (v[i] <= j) f[j] = min(f[j], f[j-v[i]] + w[i]);
            if (f[j] > mxll) f[j] = mxll + 1;
        }
    }
    for (int i=n*500;i>=0;i--) {
        if (f[i] > c) continue;
        cout << i;
        return 0;
    }
}