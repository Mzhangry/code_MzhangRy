// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, a[200005], k, x;
int main() {
    cin >> n >> k >> x;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        if (k<=0) break;
        int d = min(k, a[i]/x);
        k -= d;
        a[i] -= d*x;
    }
    if (k>0) {
        sort (a, a+n);
    }
    int sum = 0;
    for (int i=0;i<n-k;i++) sum += a[i];
    cout << sum << endl;
}