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

int n;
int g[505][505], numxy[505][505], num100[505][505];
ll ans;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> g[i][j];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (g[i][j] == 100) num100[i][j] = num100[i-1][j] + 1;
            else num100[i][j] = num100[i-1][j];
            if (g[i][j] < 100) numxy[i][j] = numxy[i-1][j] + 1;
            else numxy[i][j] = numxy[i-1][j];
        }
    }    
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            int lasxy = 0, las100 = 0;
            for (int k=1;k<=n;k++) {
                if (num100[j][k] - num100[i-1][k] > 0) las100 = k;
                if (numxy[j][k] - numxy[i-1][k] > 0) lasxy = k;
                if (las100 > lasxy) ans += las100 - lasxy;
            }
        }
    }
    cout << ans << endl;
}