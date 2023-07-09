// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Ac {
    int s, e;
    bool operator< (const Ac t) const {
        return e < t.e;
    }
} a[1005];
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].s >> a[i].e;
    sort (a, a+n);
    int ans = 0, d = -1;
    for (int i=0;i<n;i++) {
        if (a[i].s > d) {
            ans ++;
            d = a[i].e;
        }
    }
    cout << ans;
}