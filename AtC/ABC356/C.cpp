// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, m;
bool ans[105];
int c[105];
unsigned e[105];
unsigned cnt;

int now;
void dfs(int x) {
    if (x == n) {
        for (int i=0;i<m;i++) {
            if (__builtin_popcount(now&e[i]) < k && ans[i]) return;
            if (__builtin_popcount(now&e[i]) >= k && !ans[i]) return;
        }
        cnt++;
        return;
    }
    dfs(x+1);
    now |= 1 << x;
    dfs(x+1);
    now ^= 1 << x;
}
int main() {
    cin >> n >> m >> k;
    for (int i=0;i<m;i++) {
        cin >> c[i];
        for (int j=0;j<c[i];j++) {
            int a; cin >> a;
            e[i] |= (1 << (a-1));
        }
        char ch; cin >> ch;
        if (ch == 'o') ans[i] = 1;
    }
    dfs(0);
    cout << cnt << endl;
}