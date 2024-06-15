// MzhangRy - 张容钰
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const int inf = 1e9 + 10;
int n, m, k;
struct Cow {
    int w, a;
    const bool operator< (const Cow d) const {
        return w < d.w;
    }
} a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) cin >> a[i].w >> a[i].a;
    sort (a+1, a+1+n);
    deque<Cow> q; q.push_back({-inf, m}); // 只能在存在的后面接 初始化m个位置
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        int cnt = 0;
        while (!q.empty() && q.front().w + k <= a[i].w) {
            if (a[i].a >= q.front().a) { // 比它多 替换
                a[i].a -= q.front().a;
                cnt += q.front().a;
                q.pop_front();
            } else { // 比它少 结束
                cnt += a[i].a;
                q.front().a -= a[i].a;
                break;
            }
        }
        ans += cnt;
        if (cnt) q.push_back({a[i].w, cnt});
    }
    cout << ans << endl;
}