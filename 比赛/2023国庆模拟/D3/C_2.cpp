// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const int inf = 1e9;
int n, w, d;
vector<int> e[maxn]; // 反向图
int cardis[maxn], xl[maxn], wdis[maxn];
multiset<int> ans;
void bfs () {
    queue<int> q; for (int i=1;i<=n;i++) wdis[i] = inf;
    q.push(n); wdis[n] = 0;
    while (!q.empty()) {
        int d = q.front(); q.pop();
        for (int v : e[d]) {
            if (wdis[v] > wdis[d] + 1) {
                wdis[v] = wdis[d] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    cin >> n >> w >> d;
    for (int i=0;i<w;i++) {
        int a, b; cin >> a >> b;
        e[b].push_back(a);
    }
    bfs();
    for (int i=0;i<n;i++) {cin >> xl[i]; cardis[xl[i]] = i;}
    for (int i=1;i<=n;i++) ans.insert(cardis[i] + wdis[i]);
    while (d--) {
        int a, b; cin >> a >> b; a--, b--;
        ans.erase(ans.find(cardis[xl[a]] + wdis[xl[a]])); ans.erase(ans.find(cardis[xl[b]] + wdis[xl[b]]));
        swap (cardis[xl[a]], cardis[xl[b]]);
        ans.insert(cardis[xl[a]] + wdis[xl[a]]); ans.insert(cardis[xl[b]] + wdis[xl[b]]);
        swap (xl[a], xl[b]);
        cout << *ans.begin() << endl;
    }
}
