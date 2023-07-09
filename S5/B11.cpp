// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

bool h[40], z[40], y[40];
int n;
int ans[100005][15], cur[15], cnt = 1;

void dfs(int a) {
    for (int i=1;i<=n;i++) {
        if (! (h[i] | z[i-a+15] | y[i+a])) {
            cur[a] = i;
            h[i] = z[i-a+15] = y[i+a] = true;
            if (a == n-1) {
                memcpy(ans[cnt++], cur, sizeof(cur));
            } else {
                dfs(a+1);
            }
            h[i] = z[i-a+15] = y[i+a] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    for (int i=1;i<=3;i++) {
        for (int j=0;j<n;j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cout << cnt-1 << endl;
}