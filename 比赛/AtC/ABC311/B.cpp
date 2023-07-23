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

int n, d;
string s[105];
int ans;
int f[105];
int main() {
    cin >> n >> d;
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=0;i<d;i++) {
        bool flag = true;
        for (int j=1;j<=n;j++) {
            if (s[j][i] == 'x') {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (i == 0) f[0] = 1;
            else f[i] = f[i-1] + 1;
        }
    }
    for (int i=0;i<d;i++) ans = max(f[i], ans);
    cout << ans << endl;
}