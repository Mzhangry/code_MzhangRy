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
#include<set>
using namespace std;
typedef long long ll;

int n, k;
set<int> s[200005];
int a[200005], b[200005]; // a存储每个位置的牛 b存储每头牛在哪个位置
int f[200005];
int main() {
    cin >> n >> k;
    for (int i=1;i<=n;i++) s[i].insert(i);
    for (int i=1;i<=n;i++) a[i] = b[i] = i;
    for (int i=0;i<k;i++) {
        int u, v; cin >> u >> v;
        s[a[u]].insert(v); s[a[v]].insert(u);
        swap (b[a[u]], b[a[v]]);
        swap (a[u], a[v]);
    }
    for (int i=1;i<=n;i++) if (!f[i]) {
        set<int> tail;
        tail.insert(b[i]); tail.insert(i);
        while (1) {
            bool flag = false;
            for (int c : s[b[i]]) s[i].insert(c);
            b[i] = b[b[i]];
            if (!tail.insert(b[i]).second) break;
        }
        for (int c : tail) f[c] = s[i].size();
    }
    for (int i=1;i<=n;i++) cout << f[i] << endl;
}