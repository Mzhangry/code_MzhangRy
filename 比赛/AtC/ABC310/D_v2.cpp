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

int t, n, m;
int hate[15];
bool team[1<<11];
ll f[1<<10][15];
int main() {
    cin >> n >> t >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        hate[--a] |= 1 << --b;
    }
    for (int S=0;S < 1<<n;S++) {
        int m = 0;
        for (int i=0;i<n;i++) if (S >> i & 1) m |= hate[i];
        if (!(m & S)) team[S] = true; 
    }
    f[0][0] = 1;
    for (int S1 = 0; S1 < 1<<n;S1++) {
        for (int S2 = (S1 | S1+1), c=S2;S2 < 1<<n;S2 = (S2+1) | c) {
            if (team[S1 ^ S2]) {
                for (int i=1;i<=t;i++) {
                    f[S2][i] += f[S1][i-1];
                }
            }
        }
    }
    cout << f[(1<<n)-1][t] << endl;
}