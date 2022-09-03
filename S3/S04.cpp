// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, a[100005], chafen[100005];
int q;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cin >> q;
    for (int i=1;i<=n;i++) chafen[i] = a[i] - a[i-1];
    int l, r, v;
    for (int i=0;i<q;i++) {
        cin >> l >> r >> v;
        chafen[l] += v;
        chafen[r+1] -= v;
    }
    for (int i=1;i<=n;i++) {
        a[i] = chafen[i] + a[i-1];
    }
    for (int i=1;i<=n;i++) cout << a[i] << ' ';
}