// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[1000010];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        a[i] = i/m + a[i/m+i%m];
        printf("%d %d\n", i, i+a[i]);
    }
}