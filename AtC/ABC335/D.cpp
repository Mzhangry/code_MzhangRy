// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int e[50][50];
int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};
int cnt = 0;
void solve (int stx, int sty, int d) {
    if (cnt == n * n) return; cnt++;
    int edx = stx + dx[d], edy = sty + dy[d];
    if (e[edx][edy] || edx > n || edx < 1 || edy >n || edx < 1) {
        d = (d + 1) % 4;
        edx = stx + dx[d], edy = sty + dy[d];
    }
    e[edx][edy] = cnt;
    solve (edx, edy, d);
}
int main() {
    cin >> n;
    solve (0, 1, 0);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (e[i][j] == n * n) cout << 'T' << ' ';
            else cout << e[i][j] << ' ';
        }
        cout << endl;
    }
}