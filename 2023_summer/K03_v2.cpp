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
typedef pair<int, int> P;

int n, k;
char e[10][10];
set<P> now;
ll ans = 0;
bool inbound (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

void dfs (int num) {
    if (num == k) {ans++; return;}
    set<P> nex;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) if (e[i][j] == '.') {
            for (int d=0;d<4;d++) {
                int x = i + dx[d], y = j + dy[d];
                if (inbound(x, y) && e[x][y] == '!') nex.insert({i, j});
            }
        }
    }
    for (auto p : nex) {
        e[p.first][p.second] = '!';
        dfs (num+1);
        e[p.first][p.second] = '#';
    }
    for (auto p : nex) e[p.first][p.second] = '.';
}

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> e[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (e[i][j] == '.') {
                e[i][j] = '!';
                dfs (1);
                e[i][j] = '#';
            }
        }
    }
    cout << ans << endl;
}