// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> q(15);
int a[15], b[15];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> q[i];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];

    int ans = 0;
    for (int i=0;i<=2e6+10;i++) {
        bool flag = true;
        vector<int> qa(15);
        for (int j=1;j<=n;j++) {
            qa[j] = q[j] - a[j]*i;
            if (qa[j] < 0) { flag = false; break; }
        } 
        if (!flag) break;
        int cntb = 2e6 + 100;
        for (int j=1;j<=n;j++) {
            if (b[j] == 0) continue;
            cntb = min(cntb, qa[j] / b[j]);
        }
        ans = max(ans, i + cntb);
    }
    cout << ans << endl;
}