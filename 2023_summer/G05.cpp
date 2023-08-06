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
int e[2000][2000];
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
queue<P> q;
bool inbound (int x, int y) {
    return x >= 0 && y >= 0;
}
int lastans = 0;
int main() {
    cin >> n;
    for (int i=0;i<=1950;i++) for (int j=0;j<=1950;j++) e[i][j] = -1;
    
    
    while (n--) {
        int x, y; cin >> x >> y; x+=500; y+=500;
        if (e[x][y] != -1) {
            cout << --lastans << endl;
            continue;
        }

        e[x][y] = 0;
        for (int d=0;d<4;d++) {
            int xx = x + dx[d], yy = y + dy[d];
            if (inbound(xx, yy) && e[xx][yy] != -1) {
                e[x][y]++; e[xx][yy]++;
                if (e[xx][yy] == 3) q.push({xx,yy});
            }
            if (e[x][y] == 3) q.push({x, y});
        }
        int ans = lastans;
        while (!q.empty()) {
            int gx = q.front().first, gy = q.front().second; q.pop();
            for (int d=0;d<4;d++) {
                int xx = gx + dx[d], yy = gy + dy[d];
                if (inbound(xx, yy) && e[xx][yy] == -1) {
                    ans++;
                    e[xx][yy] = 0;
                    for (int dd = 0; dd<4;dd++) {
                        int xxx = xx + dx[dd], yyy = yy + dy[dd];
                        if (inbound(xxx, yyy) && e[xxx][yyy] != -1) {
                            e[xx][yy]++; e[xxx][yyy]++;
                            if (e[xxx][yyy] == 3) q.push({xxx, yyy});
                        }
                    }
                    if (e[xx][yy] == 3) q.push({xx, yy});

                    break;
                }
            }
        }
        cout << ans << endl;
        lastans = ans;
    }
}