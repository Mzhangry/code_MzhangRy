// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
typedef pair<int, int> P;

int t; ll n, l, p;
const ll inf = 1e18+1e5;
ll fpow (ll a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 1;
    ll ans = 1;
    if (b % 2 == 1) ans = a;
    ll t = fpow (a, b/2);
    // if (inf / t / ans < t) return inf+10;
    return ans * t * t;
}
int main() {
    // freopen("p1912.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> l >> p;
        vector<string> s(n+2);
        // vector<int> d(n+2);
        vector<int> trans(n+2);
        vector<ll> f(n+2, inf), sum(n+2);
        vector<int> sx;
        deque<P> q;
        for (int i=1;i<=n;i++) {cin >> s[i]; s[i] += ' ';}
        auto len = [&s] (int i) -> int {return s[i].length();};
        for (int i=1;i<=n;i++) sum[i] = sum[i-1] + len(i);
        auto w = [=] (int a, int b) -> ll {return fpow(abs(sum[b] - sum[a-1] - 1 - l), p);}; 
        f[1] = w(1, 1); f[0] = 0; q.push_back({1, 1}); // trans[1] = trans[0] = 1;
        auto cul = [&] (int num) {
            auto d = q.front(); 
            // cout << 1;
            if (num != 2) {
                // 计算前一个的f
                q.pop_front();
                while (!q.empty() && num-1 >= q.front().second) {d = q.front(); q.pop_front();}
                q.push_front(d); sx.push_back(d.first); 
                f[num-1] = f[d.first-1] + w(d.first, num-1);
                // trans[num-1] = d.first;
            }
            if (num == n + 1) return;
            // 若优于整组 则弹出整组
            d = q.back(); // first用啥转移 1 - first - 1是旧转化 first - [second, n] 都是一组
            while (num <= d.second && f[d.first-1] + w(d.first, d.second) > f[num-1] + w(num, d.second)) {q.pop_back(); if(q.empty()) break; d = q.back();}
            if (q.empty()) {q.push_back({num, d.second}); trans[d.second] = num; return;}
            // 二分
            int L = d.second, R = n, mid;
            int ok = n+1;
            while (L <= R) {
                mid = (L + R) / 2;
                ll old = f[d.first - 1] + w(d.first, mid);
                ll nw = f[num - 1] + w(num, mid);
                if (old < nw) L = mid + 1;
                else {
                    R = mid - 1;
                    ok = mid;
                }
            }
            if (ok == n+1) return;
            q.push_back({num, ok});
            trans[ok] = num;
        };
        for (int i=2;i<=n+1;i++) {
            cul(i);
        }
        sx.push_back(n+1);
        if (f[n] > (ll)1e18) cout << "Too hard to arrange" << endl;
        else {
            cout << (long long)f[n] << endl;
            // for (int i=0;i<sx.size()-1;i++) {
            //     for (int j=sx[i];j<sx[i+1];j++) {
            //         if (j != sx[i+1]-1) cout << s[j];
            //         else {for (int k=0;k<s[j].size()-1;k++) cout << s[j][k]; cout << endl;}
            //     }
            // }
            for (int i=n;i>=1;i--) {
                int f = i;
                for (int q = trans[i]; i>= q; i--) {
                    if (trans[i] > q) q = trans[i];
                    trans[i] = f;
                }
                i++;
            }
            for (int i=1;i<=n;i++) {
                if (trans[i+1] != trans[i]) {for (int j=0;j<s[i].size()-1;j++) cout << s[i][j]; cout << endl;}
                else cout << s[i];
            }
        }
        cout << "--------------------";
        if (t > 0) cout << endl;
    }
}