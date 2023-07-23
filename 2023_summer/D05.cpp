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
typedef pair<int, int> P;

int n;
P e[2005];
map<int, vector<int> > m;
int ans = 0;
bool exist (int x, int y) {
    if (m.count(x) == 0) return false;
    vector<int> v = m[x];
    for (int i=0;i<v.size();i++) {
        if (v[i] == y) return true;
    }
    return false;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a, b; cin >> a >> b;
        e[i] = make_pair(a, b);
        m[a].push_back(b);
    }
    // sort (e+1, e+n+1);
    for (int i=1;i<=n;i++) {
        int dx = e[i].first, dy = e[i].second; // 顶点
        for (int j=1;j<=n;j++) {
            if (i == j) continue;
            int x1 = e[j].first, y1 = e[j].second;
            int cx = x1 - dx, cy = y1 - dy;
            if (!(cx == 0 || cy == 0) && !(cx == cy)) { // 不在同一条直线上
                if (exist (dx - cx, dy + cy)) ans++;
                if (exist (dx + cx, dy - cy)) ans++;
                if (exist (dx - cx, dy - cy)) ans++;
                if (exist (dx + cy, dy + cx)) ans++; // 
                if (exist (dx - cy, dy - cx)) ans++; //
            }
            if (exist (dx - cy, dy + cx)) {ans++; }
            if (exist (dx + cy, dy - cx)) {ans++; }
        }
    }
    cout << ans/2 << endl;
}