// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t[5] = {0, 2, 4, 6, 8};
int main() {
    ll a; cin >> a; a--;
    vector<int> ans(100);
    int i=0;
    for (; a>0; i++) {
        ans[i] = t[a%5]; a/=5;
    }
    if (i > 0) i--;
    for (;i>=0;i--) {
        cout << ans[i];
    }
    cout << endl;
}