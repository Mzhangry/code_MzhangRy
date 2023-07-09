// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t, n, m;
int ans = 0, cnt = 0;
bool vis[15][15];
int dx[8] = {-1, 1, -2, -2, -1, 1, 2, 2},
    dy[8] = {2, 2, -1, 1, -2, -2, 1, -1};
int dfs(int a, int b) {
    cnt++;
    if (cnt == n*m) {
        cnt--;
        return 1;
    }
    vis[a][b] = true;
    
    int cur = 0;
    for (int i=0;i<8;i++) {
        int aa = a + dx[i], bb = b + dy[i];
        if (aa >= 0 && aa < n && bb >= 0 && bb < m && !vis[aa][bb]) cur += dfs(aa, bb);
    }

    vis[a][b] = false;
    cnt--;
    return cur;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a, b; cin >> a >> b;
        cout << dfs(a, b) << endl;
    }
}