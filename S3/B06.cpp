// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    int a[100010];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) {
        cin >> x;
        int l = 0, r = n-1, mid;
        while (l<=r) {
            mid = (l+r)/2;
            if (x < a[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl;
    }
}