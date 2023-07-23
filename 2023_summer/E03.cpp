// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int n;
int nxt[100005];
vector<int> b;
bool vis[100005];
int ans = 0;
void dfs (int fst, int num) {
    if (num == -1) return;
    vis[num] = true; b.push_back(num);
    if (fst == nxt[num]) {
        ans += b.size();
        for (int i : b) nxt[i] = -1;
        return;
    }
    if (!vis[nxt[num]]) dfs (fst, nxt[num]);
    return;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> nxt[i];
    for (int i=1;i<=n;i++) {
        memset (vis, 0, sizeof (vis));
        b.clear();
        dfs (i, i);
    }
    cout << ans << endl;
}