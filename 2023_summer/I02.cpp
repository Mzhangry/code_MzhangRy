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
vector<int> e[100005];
queue<int> q;
int c[100005], las[100005];
int main() {
    cin >> n;
    for (int i=2;i<=n;i++) {
        int p; cin >> p; e[p].push_back(i);
        las[i] = p;
    }
    for (int i=1;i<=n;i++) cin >> c[i];
    q.push (1);
    int ans = 0;
    while (!q.empty()) {
        int d = q.front(); q.pop();
        if (c[las[d]] != c[d]) ans++;
        for (int i : e[d]) q.push(i);
    }
    cout << ans << endl;
}