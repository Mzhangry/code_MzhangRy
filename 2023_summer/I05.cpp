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
int a[105];
int k;
vector<int> m[105];
bool make (int num) {
    if (a[num]) {
        a[num]--;
        return true;
    }
    if (m[num].empty()) return false;
    for (int c : m[num]) {
        if (!make(c)) return false;
    }
    return true;
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cin >> k;
    for (int i=0;i<k;i++) {
        int d, r; cin >> d >> r;
        while (r--) {
            int c; cin >> c;
            m[d].push_back(c);
        }
    }
    int ans = 0;
    while (1) {
        if (make(n)) ans++;
        else break;
    }
    cout << ans << endl;
}