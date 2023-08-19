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
        vector<ll> e(m, -1); e[1] = 1;
        queue<int> q; q.push(1);
        if (m == 1) {
            cout << 1 << endl;
            continue;
        }
        while (1) {
            int d = q.front(); q.pop();
            ll a1 = e[d] * 10, a2 = e[d] * 10 + 1;
            if (a1 % m == 0) {
                cout << a1 << endl; break;
            } else if (a2 % m == 0) {
                cout << a2 << endl; break;
            }
            if (e[a1 % m] == -1) {
                e[a1 % m] = a1;
                q.push(a1 % m);
            }
            if (e[a2 % m] == -1) {
                e[a2 % m] = a2;
                q.push(a2 % m);
            }
        }
    }
}