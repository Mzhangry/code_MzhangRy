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

const int maxn = 15;
int a, b;
int f[maxn][maxn];
vector<int> num;
int dfs (int pos, int las, bool lead, bool limit) {
    int ans = 0;
    if (pos == 0) return 1;
    if (!lead && !limit && f[pos][las] != -1) return f[pos][las];
    int up = limit ? num[pos-1] : 9;
    for (int i=0;i<=up;i++) {
        if (abs(i-las) < 2) continue;
        if (i==0 && lead) ans += dfs (pos - 1, -2, lead, limit && i==up);
        else ans += dfs (pos-1, i, false, limit && i==up);
    }
    if (!lead && !limit) f[pos][las] = ans;
    return ans;
}
int solve (int a) {
    num.clear();
    while (a) {
        num.push_back(a % 10);
        a /= 10;
    }
    //reverse(num.begin(), num.end());
    return dfs(num.size(), -2, true, true);
}
int main() {
    memset (f, -1, sizeof(f));
    cin >> a >> b;
    cout << solve(b) - solve(a-1) << endl;

}