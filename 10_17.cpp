// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m,ans=0,tmp,a[505];
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (m>=a[i]) {
            ans ++;
            m -= a[i];
        } else {
            break;
        }
    }
    cout << ans;
}