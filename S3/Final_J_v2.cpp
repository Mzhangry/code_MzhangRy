// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
int ans = 0;
int a[1000010];
int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        int u = a[i] + m;
        int id = upper_bound(a, a+n, u) - a;
        ans += id - i - 1;
    }
    cout << ans;
}