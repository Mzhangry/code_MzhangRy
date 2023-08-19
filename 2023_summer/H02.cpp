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

int w, h, n;
int e[105][105];
bool inbound (int x, int y) {
    return x>=0 && x<w && y>=0 && y<h;
}
int main() {
    cin >> w >> h >> n;
    for (int i=0;i<w;i++) for (int j=0;j<h;j++) e[i][j] = 1;
    for (int i=2;i<=n+1;i++) {
        int xa, xb, ya, yb; cin >> xa >> ya >> xb >> yb;
        if (xa == xb) {
            int ed = xa, y = min(ya, yb);
            while (inbound(ed+1, y) && e[ed+1][y] == e[ed][y]) ed++;
            for (int xx = xa;xx<=ed;xx++) {
                for (int yy = y; yy < max(ya, yb); yy++) {
                    e[xx][yy] = i;
                }
            }
        } else {
            int ed = ya, x = min(xa, xb);
            while (inbound(x, ed+1) && e[x][ed+1] == e[x][ed]) ed++;
            for (int xx = x; xx < max(xa, xb);xx++) {
                for (int yy = ya;yy<=ed;yy++) {
                    e[xx][yy] = i;
                }
            }
        }
    }
    vector<int> cnt(n+2);
    for (int i=0;i<w;i++) {
        for (int j=0;j<h;j++) {
            cnt[e[i][j]]++;
        }
    }
    sort (cnt.begin(), cnt.end());
    for (int i=1;i<=n+1;i++) cout << cnt[i] << ' ';
    cout << endl;
}