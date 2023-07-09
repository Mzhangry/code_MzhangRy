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
int r, c;
bool e[205][205];
int dis[205][205];
int que[205][2], head, tail;
int stx, sty, edx, edy;
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
bool inbound(int x, int y) {
    return x>=0 && x<r && y>=0 && y<c && e[x][y];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> r >> c;
        for (int i=0;i<=r;i++) {
            for (int j=0;j<=c;j++) {
                dis[i][j] = inf;
            }
        }
        head = tail = 0;
        memset(e, 0, sizeof(e));
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                char ch; cin >> ch;
                if (ch != '#') e[i][j] = true;
                if (ch == 'S') {
                    stx = i; sty = j;
                } else if (ch == 'E') {
                    edx = i; edy = j;
                }
            }
        }

        que[tail][0] = stx; que[tail][1] = sty; tail++;
        dis[stx][sty] = 0;
        while (head < tail) {
            int hx = que[head][0], hy = que[head][1]; head++;
            if (hx == edx && hy == edy) break; // ok
            for (int i=0;i<4;i++) {
                int nx = hx + dx[i], ny = hy + dy[i];
                if (inbound(nx, ny) && dis[nx][ny] == inf) {
                    dis[nx][ny] = dis[hx][hy] + 1;
                    que[tail][0] = nx; que[tail][1] = ny; tail++;
                }
            }
        }
        if (dis[edx][edy] == inf) cout << "oop!" << endl;
        else cout << dis[edx][edy] << endl;
    }
}