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

vector<bool> used;
vector< vector<int> > p;
vector<int> ans;
bool dfs (int a) {
    if (used[a]) return true;
    for (int d : p[a]) {
        if (!dfs(d)) {
            return false;
        }
    }
    ans.push_back(a);
    used[a] = true;
    return true;
}

int main() {
    int n; cin >> n;
    used.resize(n);
    vector<int> c(n);
    p.resize(n);
    for (int i=0;i<n;i++) {
        cin >> c[i];
        p[i].resize(c[i]);
        for (int j=0;j<c[i];j++) {
            cin >> p[i][j];
            p[i][j]--;
        }
    }
    dfs (0);
    for (int i=0;i<ans.size()-1;i++) cout << ans[i] + 1<< ' ';
    cout << endl;
}