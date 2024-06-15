// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, r, l;
    cin >> n >> l >> r;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) a[i] = i;
    reverse(a.begin()+l, a.begin()+r+1);
    for (int i=1;i<=n;i++) cout << a[i] << " ";
}