// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105];
int f[105], f1[105];
int cnt[105];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        f[i] = 1;
        for (int j=1;j<i;j++) {
            if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
        }
    }
    for (int i=n;i>=1;i--) {
        f1[i] = 1;
        for (int j=n;j>i;j--) {
            if (a[j] > a[i]) f1[i] = max(f1[i], f1[j] + 1); 
        }
    }
    int lis = 0;
    for (int i=1;i<=n;i++) lis = max(lis, f[i]);
    
    int ans1 = 0, ans2 = 0;
    for (int i=1;i<=n;i++) {
        if (f[i] + f1[i] - 1 == lis) {
            ans1++;
            cnt[f[i]]++;
        }
    }
    for (int i=0;i<=100;i++) if (cnt[i] == 1) ans2++; 
    cout << lis << ' ' << ans1 << ' ' << ans2;
}