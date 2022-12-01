// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n;
int a[1005], up[1005], down[1005];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (a[j] < a[i] && up[j] > up[i]) up[i] = up[j];
        }
        up[i] ++;
    }
    for (int i=n-1;i>=0;i--) {
        for (int j=n-1;j>i;j--) {
            if (a[j] < a[i] && down[j] > down[i]) down[i] = down[j];
        }
        down[i] ++;
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        ans = max(ans, up[i]+down[i]-1);
    }
    cout << ans;
}