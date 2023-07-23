// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int a[10005], x[10005];
int mi = 0, mx = 1e9;
int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i] >> x[i];
    for (int i=0;i<n;i++) {
        mi = max(a[i] / (x[i]+1), mi);
        mx = min(a[i] / x[i], mx);
    }
    cout << mi+1 << ' ' << mx;
}