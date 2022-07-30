// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int m, n, a[15], ans;
void f (int k, int yu) {
    if (k == n) {
        if (yu < a[k-1] || yu == 0) return;
        //for (int i=0;i<n;i++) cout << a[i] << ' ';
        //cout << endl;
        ans++;
        return;
    }
    for (int i=a[k-1];i<=yu;i++) {
        a[k] = i;
        f (k+1, yu-i);
    }
}
int main() {
    int t;
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> m >> n;
        ans = 0;
        f(1, m);
        cout << ans << endl;
    }
}