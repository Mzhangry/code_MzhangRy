// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

bool h[20], z[20], y[20];
int ans[105][8], cur[8], cnt = 1;

void dfs(int a) {
    for (int i=1;i<=8;i++) {
        if (! (h[i] | z[i-a+10] | y[i+a])) {
            cur[a] = i;
            h[i] = z[i-a+10] = y[i+a] = true;
            if (a == 7) {
                memcpy(ans[cnt++], cur, sizeof(cur));
            } else {
                dfs(a+1);
            }
            h[i] = z[i-a+10] = y[i+a] = false;
        }
    }
}

int main() {
    dfs(0);
    for (int i=1;i<cnt;i++) {
        cout << "NO. " << i << endl;
        for (int j=0;j<8;j++) {
            for (int k=1;k<=8;k++) {
                if (ans[i][k-1] == j+1) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << endl;
        }
    }
}