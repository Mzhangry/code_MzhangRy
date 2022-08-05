// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m;
    int a[1000010];
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i];
    int x;
    for (int i=0;i<m;i++) {
        cin >> x;
        int lb = lower_bound(a, a+n, x) - a;
        if (lb == 0) cout << "not found" << endl;
        else cout << a[lb-1] << endl;
    }
}