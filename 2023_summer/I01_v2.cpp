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
int main() {
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    int mx = -1, se = -1;
    vector<int> cnt(n+1);
    for (int d : a) {
        if (d > mx) {
            se = mx;
            mx = d;
            cnt[mx]--;
        } else if (d > se) {
            se = d;
            cnt[mx]++;
        }
    }
    int ans = 1;
    mx = -1e9;
    for (int i=1;i<=n;i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            ans = i;
        }
    }
    cout << ans << endl;
}