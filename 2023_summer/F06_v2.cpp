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
const ll inf = 1e18;

vector< vector<bool> > e;
int n, m;
queue<P> q;
P st, ed;
char stfor;
map<char, vector<P> > mp;

void chushihua () {
    mp['K'] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    mp['N'] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
}

bool inbound (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && e[x][y];
}
// void tihuan (int xx, int yy, int num, P d) {
//     f[xx][yy][num] = f[d.first][d.second][num] + 1;
//     for (int i=0;i<4;i++) if (num != i) {
//         f[xx][yy][i] = min(f[xx][yy][num]+1, f[xx][yy][i]);
//     }
//     q.push({xx, yy});
// }
map<char, int> cor = {{'K',0}, {'N',1}, {'R',2}, {'B',3}};
int main() {
    chushihua();
    int t; cin >> t;
    while (t--) {
        e.clear();
        cin >> n >> m >> stfor;
        ll f[n+1][m+1][4];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) for (int k=0;k<4;k++) f[i][j][k] = inf;
        for (int i=0;i<n;i++) {
            vector<bool> e1;
            for (int j=0;j<m;j++) {
                char c; cin >> c; bool b = false;
                if (c != '#') b = true;
                e1.push_back(b);
                if (c == 'S') st = {i, j};
                else if (c == 'T') ed = {i, j};
            }
            e.push_back(e1);
        }
        q.push(st); f[st.first][st.second][cor[stfor]] = 0;
        for (int i=0;i<4;i++) if (f[st.first][st.second][i]) f[st.first][st.second][i] = 1;
        vector<bool> vis[2][n+1][m+1];
        for (int i=0;i<2;i++) for (int j=0;j<n;j++) for (int k=0;k<m;k++) vis[i][j][k].resize(4);
        while (!q.empty()) {
            P d = q.front(); q.pop();
            // if (d == ed) break;
            for (int i=0;i<mp['K'].size();i++) {
                int xx = mp['K'][i].first + d.first, yy = mp['K'][i].second + d.second;
                if (!inbound(xx, yy) ) continue;
                if (f[xx][yy][0] > f[d.first][d.second][0] + 1) {
                    f[xx][yy][0] = f[d.first][d.second][0] + 1;
                    f[xx][yy][1] = min (f[xx][yy][0] + 1, f[xx][yy][1]);
                    f[xx][yy][2] = min (f[xx][yy][0] + 1, f[xx][yy][2]);
                    f[xx][yy][3] = min (f[xx][yy][0] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } 
            }

            for (int i=0;i<mp['N'].size();i++) {
                int xx = mp['N'][i].first + d.first, yy = mp['N'][i].second + d.second;
                if (!inbound(xx, yy) ) continue;
                if (f[xx][yy][1] > f[d.first][d.second][1] + 1) {
                    f[xx][yy][1] = f[d.first][d.second][1] + 1;
                    f[xx][yy][0] = min (f[xx][yy][1] + 1, f[xx][yy][0]);
                    f[xx][yy][2] = min (f[xx][yy][1] + 1, f[xx][yy][2]);
                    f[xx][yy][3] = min (f[xx][yy][1] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } 
            }
         ////////////////////// R ///////////////////// 
            for (int xx = d.first-1, yy = d.second;inbound(xx, yy);xx--) {
                
                if (f[xx][yy][2] > f[d.first][d.second][2] + 1) {
                    vis[0][xx][yy][0] = true;
                    f[xx][yy][2] = f[d.first][d.second][2] + 1;
                    f[xx][yy][0] = min (f[xx][yy][2] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][2] + 1, f[xx][yy][1]);
                    f[xx][yy][3] = min (f[xx][yy][2] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } else if (vis[0][xx][yy][0]) break;
            }

            for (int xx = d.first+1, yy = d.second;inbound(xx, yy);xx++) {
                if (f[xx][yy][2] > f[d.first][d.second][2] + 1) {
                    vis[0][xx][yy][1] = true;
                    f[xx][yy][2] = f[d.first][d.second][2] + 1;
                    f[xx][yy][0] = min (f[xx][yy][2] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][2] + 1, f[xx][yy][1]);
                    f[xx][yy][3] = min (f[xx][yy][2] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } else if (vis[0][xx][yy][1]) break;
            }

            for (int xx = d.first, yy = d.second-1;inbound(xx, yy);yy--) {
                
                if (f[xx][yy][2] > f[d.first][d.second][2] + 1) {
                    vis[0][xx][yy][2] = true;
                    f[xx][yy][2] = f[d.first][d.second][2] + 1;
                    f[xx][yy][0] = min (f[xx][yy][2] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][2] + 1, f[xx][yy][1]);
                    f[xx][yy][3] = min (f[xx][yy][2] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } else if (vis[0][xx][yy][2]) break;
            }

            for (int xx = d.first, yy = d.second+1;inbound(xx, yy);yy++) {
                
                if (f[xx][yy][2] > f[d.first][d.second][2] + 1) {
                    vis[0][xx][yy][3] = true;
                    f[xx][yy][2] = f[d.first][d.second][2] + 1;
                    f[xx][yy][0] = min (f[xx][yy][2] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][2] + 1, f[xx][yy][1]);
                    f[xx][yy][3] = min (f[xx][yy][2] + 1, f[xx][yy][3]);
                    q.push({xx, yy});
                } else if (vis[0][xx][yy][3]) break;
            }
        ////////// B /////////
            for (int xx = d.first-1, yy = d.second-1;inbound(xx, yy);xx--,yy--) {
                
                if (f[xx][yy][3] > f[d.first][d.second][3] + 1) {
                    vis[1][xx][yy][0] = true;
                    f[xx][yy][3] = f[d.first][d.second][3] + 1;
                    f[xx][yy][0] = min (f[xx][yy][3] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][3] + 1, f[xx][yy][1]);
                    f[xx][yy][2] = min (f[xx][yy][3] + 1, f[xx][yy][2]);
                    q.push({xx, yy});
                } else if (vis[1][xx][yy][0]) break;
            } 

            for (int xx = d.first+1, yy = d.second+1;inbound(xx, yy);xx++,yy++) {
               
                if (f[xx][yy][3] > f[d.first][d.second][3] + 1) {
                    vis[1][xx][yy][1] = true;
                    f[xx][yy][3] = f[d.first][d.second][3] + 1;
                    f[xx][yy][0] = min (f[xx][yy][3] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][3] + 1, f[xx][yy][1]);
                    f[xx][yy][2] = min (f[xx][yy][3] + 1, f[xx][yy][2]);
                    q.push({xx, yy});
                } else if (vis[1][xx][yy][1]) break;
            }

            for (int xx = d.first-1, yy = d.second+1;inbound(xx, yy);xx--,yy++) {
                
                if (f[xx][yy][3] > f[d.first][d.second][3] + 1) {
                    vis[1][xx][yy][2] = true;
                    f[xx][yy][3] = f[d.first][d.second][3] + 1;
                    f[xx][yy][0] = min (f[xx][yy][3] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][3] + 1, f[xx][yy][1]);
                    f[xx][yy][2] = min (f[xx][yy][3] + 1, f[xx][yy][2]);
                    q.push({xx, yy});
                } else if (vis[1][xx][yy][2]) break;
            }

            for (int xx = d.first+1, yy = d.second-1;inbound(xx, yy);xx++,yy--) {
                
                if (f[xx][yy][3] > f[d.first][d.second][3] + 1) {
                    vis[1][xx][yy][3] = true;
                    f[xx][yy][3] = f[d.first][d.second][3] + 1;
                    f[xx][yy][0] = min (f[xx][yy][3] + 1, f[xx][yy][0]);
                    f[xx][yy][1] = min (f[xx][yy][3] + 1, f[xx][yy][1]);
                    f[xx][yy][2] = min (f[xx][yy][3] + 1, f[xx][yy][2]);
                    q.push({xx, yy});
                } else if (vis[1][xx][yy][3]) break;
            }
        }
        ll ans = inf;
        // for (int k=0;k<4;k++){
        //         for (int i=0;i<n;i++) {
        //             for (int j=0;j<m;j++) {
        //                 cout << (f[i][j][k] == inf? -1 : f[i][j][k] )<< ' ';
        //             }
        //             cout << endl;
        //         }   
        //         cout << '/' << endl;
        //     }
        for (int i=0;i<4;i++) ans = min(ans, f[ed.first][ed.second][i]);
        if (ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
}