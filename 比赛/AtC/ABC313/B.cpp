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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> e[55];
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        e[b].push_back(a);
    }
    bool flag = false;
    int ans;
    for (int i=1;i<=n;i++) {
        if (e[i].empty()) {
            if (flag == false) {
                flag = true;
                ans = i;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
}