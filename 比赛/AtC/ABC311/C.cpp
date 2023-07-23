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
int e[200005];
vector<int> bmax, b;
bool vis[200005];
void dfs (int fst, int num) {
    if (vis[num]) {
        for (int i=0;i<b.size();i++) {
            if (b[i] == num) {
                cout << b.size() - i << endl;
                for (int j=i;j<b.size();j++) cout << b[j] << ' ';
                cout << endl;
                exit (0);
            }
        }
    }
    vis[num] = true; b.push_back(num);
    dfs (fst, e[num]);
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> e[i];
    for (int i=1;i<=n;i++) {
        b.clear();
        if (!vis[i]) dfs(i, i);
    }
    // cout << bmax.size() << endl;
    // for (int i: bmax) cout << i << ' ';
    // cout << endl;
}