#include <bits/stdc++.h>
using namespace std;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector g(n, vector<int>(m));
  vector h(g);

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < m; j ++) {
      cin >> g[i][j];
      g[i][j] --;
    }
  }
  for (int i = 0; i < m; i ++) {
    bitset<10001> vis;
    vector<int> st(n, -1);
    function<bool(int)> dfs = [&](int u) {
      vis[u] = true;
      for (int v : g[u]) {
        if (!~st[v] || (!vis[st[v]] && dfs(st[v]))) {
          st[v] = u;
          return true;
        }
      }
      return false;
    };
    for (int j = 0; j < n; j ++) {
      vis.reset();
      dfs(j);
    }
    for (int j = 0; j < n; j ++) {
      h[st[j]][i] = j + 1;
    }
    for (int j = 0; j < n; j ++) {
      g[st[j]].erase(find(g[st[j]].begin(), g[st[j]].end(), j));
    }
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i ++, cout << '\n') 
    for (int j = 0; j < m; j ++)
      cout << h[i][j] << ' ';
  return 0;
}