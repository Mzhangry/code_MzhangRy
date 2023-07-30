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

int n, m;
int a[200005], b[200005];
int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    sort (a, a+n); sort (b, b+m);
    ll left = 1, right = 1e9+5, mid;
    while (left < right) {
        mid = (left + right) / 2;
        int ida = upper_bound(a, a+n, mid) - a;
        int idb = lower_bound(b, b+m, mid) - b;
        idb = m-idb;
        if (ida >= idb) right = mid;
        else left = mid+1;
    }
    cout << right << endl;
}