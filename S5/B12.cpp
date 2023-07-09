// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

char m[10][10];
int n, k;
bool h[10];
int cnt;
int ans = 0;
void dfs(int a) {
    if (a == n) return;
    for (int i=0;i<n;i++) {
        if (!h[i] && m[a][i] == '#') {
            h[i] = true; cnt++;
            if (cnt == k) ans++;
            else dfs (a+1);
            h[i] = false; cnt--;
        }
    }
    dfs (a+1);
}

int main() {
    while (cin >> n >> k) {
        if (n == -1) return 0;
        ans = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cin >> m[i][j];
            }
        }
        dfs(0);
        cout << ans << endl;
    }
}