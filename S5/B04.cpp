// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


int n, m;
bool vis[20];
vector<int> e[20];
int dfs (int a) {
    vis[a] = true;
    int sum = 0;
    for (int i: e[a]) {
        if (!vis[i]) {
            sum += dfs(i);
        }
    }
    vis[a] = false;
    if (a == n) return 1;
    return sum;
}
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout << dfs(1);
}