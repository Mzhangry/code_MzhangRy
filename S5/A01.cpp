// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[6] = {500, 100, 50, 10, 5, 1};
int ans = 0;
int main() {
    int n;
    cin >> n;
    for (int i=0;n>0;i++) {
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans;
}