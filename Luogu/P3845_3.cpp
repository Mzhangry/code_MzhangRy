// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
int n;
int lds (auto e) { // 根据dilworth定理 不下降链的最小划分数为其反链 -> 最长下降子序列
    vector<ll> last(2); last[0] = 1e16; last[1] = e[0].second;
    for (int i=1;i<n;i++) {
        auto it = upper_bound (last.begin()+1, last.end(), e[i].second, greater<int>()); // 严格小于
        if (*prev(it) == e[i].second) continue;
        if (it == last.end()) last.push_back(e[i].second);
        else *it = e[i].second;
    }
    return last.size();
}
int main() {
    ios::sync_with_stdio(false);
    int t = read();
    while (t--) {
        n = read();
        vector<P> e(n);
        for (int i=0;i<n;i++) {
            e[i].first = read(), e[i].second = read();
            if (e[i].first < e[i].second) swap(e[i].first, e[i].second);
        }
        sort(e.begin(), e.end());
        cout << lds(e)-1 << endl;
    }
}