// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, x;
    int a[100010];
    cin >> n >> x;
    for (int i=0;i<n;i++) cin >> a[i];
    int l = 0, r = n-1, ans = -1;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (x == a[mid]) {
            ans = mid;
            break;
        } else if (x < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}