// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string ans;
int n;
int a[100005];
int pos = 0;
int d = 1;
int main() {
    cin >> n;
    for (int i=0;i<=n-1;i++) cin >> a[i];
    while (1) {
        if (d == 1 && a[pos] == 0) d = 0;
        if (pos == 0 && a[pos] == 0) break;
        if (d == 0 && (pos == 0 || a[pos-1] == 1) && a[pos] != 0) d = 1;
        if (d == 1) {
            a[pos]--;
            pos ++;
            ans += 'R';
        } else {
            a[pos-1]--;
            pos --;
            ans += 'L';
        }
    }
    cout << ans;
}