// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a[20], num = 0, ans = 0;
    for (int i=0;;i++) {
        cin >> a[i];
        if (a[i] == 0) break;
        else num ++;
    }
    for (int i=0;i<num;i++) {
        for (int j=0;j<num;j++) {
            if (a[i] == 2*a[j]) ans++;
        }
    }
    cout << ans;
}