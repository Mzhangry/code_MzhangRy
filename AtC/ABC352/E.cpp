// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
const int maxn = 2e5 + 10;
struct Eage {
    int cost;
    vector<int> vec;
    const bool operator < (const Eage &a) const {
        return cost < a.cost;
    }
};
vector<Eage> e;

int s[maxn];
void init() {
    for (int i=1;i<=n;i++) s[i] = i;
}
int find(int x) {
    if (s[x] == x) return x;
    return s[x] = find(s[x]);
}
void merge(int x, int y) {
    s[find(x)] = find(y);
}
int main() {
    cin >> n >> m;
    for (int t=0;t<m;t++) {
        int k, c; cin >> k >> c;
        e.push_back({c, vector<int>()});
        for (int i=0;i<k;i++) {
            int a; cin >> a;
            e.back().vec.push_back(a);
        }
    }
    sort(e.begin(), e.end());
    init();
    ll sum = 0;
    for (auto d : e) {
        for (int i=1;i<d.vec.size();i++) {
            if (find(d.vec[i]) != find(d.vec[i-1])) {
                merge(d.vec[i], d.vec[i-1]);
                sum += d.cost;
            }
        }
    }
    bool flag = true;
    for (int i=2;i<=n;i++) {
        if (find(i) != find(i-1)) {
            flag = false;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
    else cout << sum << endl;
}