// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
pair<int, int> s[500];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        s[i] = {a, i};
    }
    for (int i=1;i<=m;i++) {
        int a; cin >> a;
        s[i+n] = {a, -100};
    }
    sort(s+1, s+n+m+1);
    for (int i=1;i<n+m;i++) {
        if (abs(s[i].second - s[i+1].second) == 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
}