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
#include<set>
using namespace std;
typedef long long ll;

int mx = 0;
int a[150];
int n;
bool used[150];
set<int> s;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) mx = max(a[i], mx);
    for (int i=1;i<=n;i++) {
        if (!used[i] && !s.count(i)) {
            for (int j=1;j<=n;j++) if (i != j) {
                if ((ll)a[i] * a[j] == mx) {
                    used[i] = used[j] = true;
                    s.insert(i); s.insert(j);
                    break;
                }
            }
        }
    }
    int mx2 = 0;
    for (int i=1;i<=n;i++) if (!used[i]) mx2 = max(mx2, a[i]);
    cout << mx << ' ' << mx2 << endl;
}