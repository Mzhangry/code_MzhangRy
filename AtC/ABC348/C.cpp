// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
unordered_map<int, int> m;
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        int a, c; cin >> a >> c;
        if (m[c] == 0) m[c] = a;
        else m[c] = min(m[c], a);
    }
    int ans = -1;
    for (auto d : m) {
        ans = max(ans, d.second);
    }
    cout << ans << endl;
}