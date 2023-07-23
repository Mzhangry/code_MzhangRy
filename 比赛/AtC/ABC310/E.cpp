// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[1000005];
int n;
long long ans;
int las[1000005];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        char c = getchar();
        if (c == '0') a[i] = 0;
        else a[i] = 1;
    }
    for (int i=1;i<=n;i++) {
        if (a[i] == 0) las[i] = i;
        else if (las[i-1] != 0) las[i] = las[i-1];
    }
    for (int i=1;i<=n;i++) {
        if (a[i] == 0) ans += i-1;
        else ans += las[i] + 1;
    }
    cout << ans;
}