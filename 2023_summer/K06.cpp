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

vector<int> head (52*52*60, -1); // 链式前向星
vector<int> out (52*52*60, 0); // 出度
vector<int> f (52*52*60, -1); // 先手赢/输 / 未判断-1
struct Edge {
    int to, next = -1;
};
vector<Edge> re;
int n;
bool isUpper (char c) {
    return c >= 'A' && c <= 'Z';
}
int mul[3] = {52*52, 52, 1};
int num (string s) {
    int ans = 0;
    for (int i=0;i<3;i++) {
        if (isUpper(s[i])) ans += (s[i] - 'A' + 26) * mul[i];
        else ans += (s[i] - 'a') * mul[i];
    }
    return ans;
}
int cnt = 0;
void addEdge (int u, int v) {
    re[cnt].next = head[v];
    re[cnt].to = u;
    head[v] = cnt++;
}
queue<int> q;
int main() {
    cin >> n;
    re.resize(n+1);
    vector<int> a;
    while (n--) {
        string s; cin >> s;
        int u = num (s.substr(0, 3)), v = num(s.substr(s.length()-3, 3));
        out[u]++;
        a.push_back(v);
        addEdge (u, v);
    }
    for (int d : a) {
        if (!out[d] && f[d] != true) {
            q.push(d);
            f[d] = true;
        }
    }
    while (!q.empty()) {
        int d = q.front(); q.pop();
        if (f[d] == false) {
            for (int i = head[d]; i != -1; i = re[i].next) {
                int t = re[i].to;
                out[t]--;
                if (!out[t]) {
                    f[t] = true;
                    q.push(t);
                }
            }
        } else {
            for (int i = head[d]; i != -1; i = re[i].next) {
                int t = re[i].to;
                f[t] = false;
                q.push (t);
            }
        }
    }
    for (int d : a) {
        if (f[d] == true) cout << "Takahashi" << endl;
        else if (f[d] == false) cout << "Aoki" << endl;
        else cout << "Draw" << endl;
    }
}