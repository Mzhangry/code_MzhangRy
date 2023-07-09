// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int inf = 1e8;
int n;
int stx, sty, edx, edy;
int dis[305][305];
int que[305*305][2], head, tail;
int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2},
    dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
bool inbound (int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        cin >> stx >> sty >> edx >> edy;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                dis[i][j] = inf;
            }
        }
        head = tail = 0;
        que[tail][0] = stx; que[tail][1] = sty; tail++;
        dis[stx][sty] = 0;
        while (head < tail) {
            int hx = que[head][0], hy = que[head][1]; head++;
            if (hx == edx && hy == edy) break;
            for (int i=0;i<8;i++) {
                int nx = hx + dx[i], ny = hy + dy[i];
                if (inbound(nx, ny) && dis[nx][ny] == inf) {
                    dis[nx][ny] = dis[hx][hy] + 1;
                    que[tail][0] = nx; que[tail][1] = ny; tail++;
                }
            }
        }
        cout << dis[edx][edy] << endl;
    }
}