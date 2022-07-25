// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, cnt[1005], a, ans=0;
    cin >> n;
    for (int i=1;i<=1000;i++) cnt[i] = 0;
    for (int i=0;i<n;i++) {
        cin >> a;
        cnt[a] ++;
    }
    for (int i=1;i<=1000;i++) {
        if (cnt[i] >= 1) ans ++;
    }
    cout << ans <<endl;
    for (int i=1;i<=1000;i++) {
        if (cnt[i] >= 1) cout << i << ' ';
    }
}