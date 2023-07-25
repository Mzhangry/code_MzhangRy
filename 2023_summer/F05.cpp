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

int f[25][3];
int n, tim;
char gest[3] = {'R', 'S', 'P'};
char a[100005];
int main() {
    cin >> n >> tim;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=tim;j++) {
            for (int k=0;k<3;k++) {
                if (a[i] == gest[k]) {
                    f[j][k] ++;
                    if (j>0) for (int t=0;t<3;t++) if (t != k) {
                        f[j][k] = max(f[j][k], f[j-1][t] + 1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=tim;i++) for (int j=0;j<3;j++) ans = max(ans, f[i][j]);
    cout << ans << endl;
}