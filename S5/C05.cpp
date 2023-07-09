// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int inf = 1e8;
int n, m;
vector<int> e[100005];
int tim[100005];
int c;
int que[100005], head, tail;
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) tim[i] = inf;
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i=0;i<3;i++) {
        cin >> c;
        e[0].push_back(c);
    }
    que[tail++] = 0; tim[0] = 0;
    while (head < tail) {
        int d = que[head++];
        for (int i=0;i<e[d].size();i++) {
            int v = e[d][i];
            if (tim[v] > tim[d] + 1) {
                tim[v] = tim[d] + 1;
                que[tail++] = v;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (tim[i] == inf) cout << -1 << endl;
        else cout << tim[i] << endl;
    }
}