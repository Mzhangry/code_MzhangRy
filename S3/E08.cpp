// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int cnt[205];
int main() {
    int n,m;
    cin >> n >> m;
    int a[205];
    for (int i=0;i<n;i++) {
        cin >> a[i];
        cnt[ a[i] ] ++;
    }
    for (int i=0;i<n;i++) {
        if (cnt[a[i]] == 1) cout << "BeiJu" << endl;
        else cout << cnt[a[i]] - 1 << endl;
    }
}