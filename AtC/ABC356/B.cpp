// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m+1), sum(m+1);
    for (int i=1;i<=m;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=1;j<=m;j++) {
            int t; cin >> t;
            sum[j] += t;
        }
    }
    for (int i=1;i<=m;i++) if (sum[i] < a[i]) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}