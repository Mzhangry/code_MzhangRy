// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int f[205][105];
struct Node {
    int v, d;
};
vector<Node> e[205];
int sum[205];

void dfs(int d, int fa) {
    for (Node p : e[d]) {
        if (p.v == fa) continue;
        dfs (p.v, d);
        sum[d] += sum[p.v] + 1;
        for (int i = min(q, sum[d]); i>=0; i--) { // d节点为根的子树共i个树枝
            for (int j=0;j<=min(sum[p.v], i-1);j++) { // 其中v上有j个枝条
                f[d][i] = max(f[d][i], f[p.v][j] + p.d + f[d][i-j-1]);
            }
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i=0;i<n-1;i++) {
        int u, v, d; cin >> u >> v >> d;
        e[u].push_back({v, d}); e[v].push_back({u, d});
    }
    dfs(1, 0);
    cout << f[1][q] << endl;
}