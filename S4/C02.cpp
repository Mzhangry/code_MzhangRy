// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n;
int a[20], f[20];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=i-1;j>=0;j--) {
            if (a[j] >= a[i] && f[j] > f[i]) f[i] = f[j];
        }
        f[i]++;
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        ans = max(ans, f[i]);
    }
    cout << ans;
}