// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> P;

const int inf = 1e8;
int n, m;
int pos[105][105];
char e[105][105];
queue<P> q;
P las[105][105];
P st, ed;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2},
    dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool inbound(P a) {
    int x = a.first, y = a.second;
    return x>0 && x<=n && y>0 && y<=m; 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        queue<P> q;
        cin >> n >> m;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cin >> e[i][j];
                if (e[i][j] == 'S') st = make_pair(i, j);
                if (e[i][j] == 'E') ed = make_pair(i, j);
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                pos[i][j] = inf;
            }
        }

        q.push(st); pos[st.first][st.second] = 0;
        while (!q.empty()) {
            P d = q.front(); q.pop();
            if (d == ed) break;
            for (int i=0;i<8;i++) {
                P v(d.first + dx[i], d.second + dy[i]);
                if (inbound(v) && e[v.first][v.second]!='#' && pos[v.first][v.second] == inf) {
                    pos[v.first][v.second] = pos[d.first][d.second] + 1;
                    q.push(v);
                    las[v.first][v.second] = d;
                }
            }
        }
        if (pos[ed.first][ed.second] == inf) cout << -1 << endl;
        else {
            cout << pos[ed.first][ed.second] << endl;
            P d = ed;
            vector<P> ans;
            while (d != st) {
                ans.push_back(d);
                d = las[d.first][d.second];
            }
            ans.push_back(st);
            for (int i=ans.size()-1;i>=0;i--) {
                cout << ans[i].first << ' ' << ans[i].second << endl;
            }
        }
        cout << endl;
    }
}