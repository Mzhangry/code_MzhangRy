// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int n, q;
ll a[100005];
int main() {
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (q--) {
        ll k; cin >> k;
        ll left = 1, right = 1e18 + 1e5 + 10, mid; // 二分ans
        while (left < right) {
            mid = (left + right) / 2;
            int id = upper_bound (a+1, a+1+n, mid) - a - 1 - 1;
            if (a[id] == mid) mid++;
            
        }
    }
}