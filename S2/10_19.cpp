// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int t,n,a[10005],j;
    cin >> t;
    for (int k=0;k<t;k++) {
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        bool flag = true;
        for (int i=1;i<=n;i++) {
            for (j=0;j<n;j++) if (a[j] == i) break;
            if (j==n) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
}