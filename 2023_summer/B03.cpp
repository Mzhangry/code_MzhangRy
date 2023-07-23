// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
int f[maxn], c[maxn], b1[maxn], b2[maxn];
long long mergesort (int st, int ed) {
    if (st == ed) return 0;
    int mid = (st + ed) / 2;
    ll ansl = mergesort(st, mid), ansr = mergesort(mid+1, ed);
    int left = st, right = mid+1; ll anslr = 0;
    for (int i=st;i<=ed;i++) {
        if (right > ed || left <= mid && b1[left] < b1[right]) {
            b2[i] = b1[left++];
            anslr += right - mid - 1;
        } else {
            b2[i] = b1[right++];
        }
    }
    for (int i=st;i<=ed;i++) b1[i] = b2[i];
    return ansl + ansr + anslr;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        f[a] = i;
    }
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int i=1;i<=n;i++) c[i] = f[c[i]];
    memcpy (b1, c, sizeof(b1));
    ll ans, mi; ans = mi = mergesort (1, n);
    for (int i=n;i>0;i--) {
        ans += 2*c[i] - n - 1;
        //cout << ans << ' ';
        mi = min (ans, mi);
    }
    cout << mi;
}