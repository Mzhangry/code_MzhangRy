// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 5000) {
        int a[5005];
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n-1;i++) {
            for (int j=0;j<n-1;j++) {
                if (a[j] > a[j+1]) swap(a[j], a[j+1]);
            }
        }
        int i = 0,j,cnt;
        while (i<n) {
            cnt = 1;
            for (j=i+1;j<n;j++) {
                if (a[j] == a[i]) cnt ++;
                else {
                    cout << a[i] << ' ' << cnt << endl;
                    break;
                }
            }
            i = j;
        }
        cout << a[n-1] << ' ' << cnt << endl;
    } else {
        int a;
        int cnt[300];
        for (int i=1;i<=256;i++) cnt[i] = 0;
        for (int i=0;i<n;i++) {
            cin >> a;
            cnt[a] ++;
        }
        for (int i=1;i<=256;i++) {
            if (cnt[i] != 0) cout << i << ' ' << cnt[i] << endl;
        }
    }
}
