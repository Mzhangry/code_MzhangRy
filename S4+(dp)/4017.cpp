// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[105][105], f[105][105];
int r, c;
struct Point {
    int x, y, h;
    bool operator< (const Point &r) const {
        return h < r.h;
    }
} p[10005];
int cnt = 1;
int dx[4] = {0, 0, 1, -1},
    dy[4] = {1, -1, 0, 0};
bool ok (int x, int y) {
    if (x >= 1 && x <= r && y >= 1 && y <= c) return true;
    return false;
}

int main() {
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> a[i][j];
            p[cnt].x = i; p[cnt].y = j;
            p[cnt].h = a[i][j];
            cnt ++;
        }
    }
    cnt --;
    sort (p+1, p+cnt+1);
    for (int i=1;i<=cnt;i++) {
        f[p[i].x][p[i].y] = 1;
        for (int d=0;d<4;d++) {
            int x1 = p[i].x + dx[d], y1 = p[i].y + dy[d];
            if (ok(x1, y1) && a[p[i].x][p[i].y] > a[x1][y1]) f[p[i].x][p[i].y] = max(f[p[i].x][p[i].y], f[x1][y1] + 1); 
        }
    }
    int ans = 0;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
}