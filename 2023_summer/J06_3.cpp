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

int t;
int main() {
    cin >> t;
    while (t--) {
        ll m; cin >> m;
        vector<int> v(m, -1), pre(m, -1); v[1] = 1; pre[1] = 0;
        queue<int> q; q.push(1);
        if (m == 1) {
            cout << 1 << endl;
            continue;
        }
        while (1) {
            int d = q.front(); q.pop();
            for (int i=0;i<=1;i++) {
                int a = (d * 10 + i) % m;
                if (v[a] == -1) {
                    v[a] = i;
                    pre[a] = d;
                    q.push(a);
                }
            }
            if (v[0] != -1) break;
        }
        int d = 0;
        vector<int> ans;
        while (pre[d] != 0) {
            ans.push_back(v[d]);
            d = pre[d];
        } ans.push_back(1);
        for (int i=ans.size()-1;i>=0;i--) {
            cout << ans[i];
        }
        cout << endl;
    }
}