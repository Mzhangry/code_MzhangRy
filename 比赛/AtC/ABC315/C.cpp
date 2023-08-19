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
typedef pair<int, int> P;

bool cmp (P a, P b) {
    return a.first > b.first;
}

int main() {
    int n; cin >> n;
    vector<P> a(n);
    for (int i=0;i<n;i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end(), cmp);
    ll ans1 = a[0].first + a[1].first / 2, ans2 = -1;
    for (int i=1;i<n;i++) {
        if (a[i].second != a[0].second) {
            ans2 = a[0].first + a[i].first;
            break;
        }
    }
    cout << max (ans1, ans2) << endl;
}