// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int h[10005];
int main() {
    int n;
    long long s;
    cin >> n >> s;
    for (int i=0;i<n;i++) cin >> h[i];
    sort (h, h+n);
    int ans = 0, i = n-1;
    while (s>0) {
        ans++;
        s -= h[i];
        i--;
    }
    cout << ans;
}