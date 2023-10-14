// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
struct Person {
    ll x, y, to = -1;
};
vector< vector<Person> > f;
vector< Person > ans;
void dfs (int a) {
    vector<Person> p = f[a];
    for (auto d : p) {
        if (ans[d.to].to == -1) {
            ans[d.to].x = ans[a].x + d.x; ans[d.to].y = ans[a].y + d.y; ans[d.to].to = 1;
            dfs (d.to);
        }
    }
}
int main() {
    cin >> n >> m;
    f.resize(n+1); ans.resize(n+1);
     ans[1] = {0, 0, 1};
    while (m--) {
        int a, b, X, Y; cin >> a >> b >> X >> Y; f[a].push_back({X, Y, b}); f[b].push_back({-X, -Y, a});
    }
    dfs(1);
    for (int i=1;i<=n;i++) {
        if (ans[i].to == -1) cout << "undecidable" << endl;
        else cout << ans[i].x << ' ' << ans[i].y << endl;
    }
}