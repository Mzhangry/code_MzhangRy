// MzhangRy - 张容钰
#include<atcoder/modint>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
int main() {
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        m -= a[i];
        if (m < 0) {cout << i << endl; return 0;}
    }
    cout << n << endl;
}