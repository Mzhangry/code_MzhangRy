// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> deg(30);
int n, m;
vector<int> e[30];
int main() {
    cin >> n >> m;
    for (int _ = 1; _ <= m; _++) {
        char uc, vc; scanf ("\n%c<%c", &uc, &vc);
        int u = uc - 'A', v = vc - 'A';
        e[u].push_back(v);
        deg[v]++;
        queue<int> q;
        bool buzu = false;
        for (int i=0;i<n;i++) if (deg[i] == 0) q.push(i);
        if (q.size() > 1) buzu = true;
        vector<int> ans;
        vector<int> degc = deg;
        while (!q.empty()) {
            int d = q.front(); q.pop(); ans.push_back(d);
            bool flag = false;
            for (int v : e[d]) {
                if (--degc[v] == 0) {
                    if (flag) buzu = true;
                    q.push(v); flag = true;
                }
            }
        }
        if (ans.size() < n) {cout << "Inconsistency found after " << _ << " relations.\n"; return 0;}
        else if (buzu) continue;
        else {
            cout << "Sorted sequence determined after " << _ << " relations: ";
            for (int d : ans) cout << char(d + 'A');
            cout << '.' << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl;
}