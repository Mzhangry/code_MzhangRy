// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m, x;
    int a[100010];
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) {
        int l = 0, r = n-1, mid, ans = -1;
        cin >> x;
        while (l<=r) {
            mid = (l+r) / 2;
            if (a[mid] == x) {
                ans = mid;
                break;
            } else if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}