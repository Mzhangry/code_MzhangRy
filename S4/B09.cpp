// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[1005], ans[1005];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        if (a[i] == a[i-1]) ans[i] = ans[i-1]+1;
        else ans[i] = 1;
    }
    int t = 0;
    for (int i=1;i<=n;i++) {
        t = max(t, ans[i]);
    }
    cout << t;
}