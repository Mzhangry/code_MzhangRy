// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int a[1005], d[1005];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) d[i] = a[i] - a[i-1];
    for (int i=0;i<m;i++) {
        int dmax = 0, mid;
        for (int i=2;i<=n;i++) {
            if (abs(d[i+1] - d[i] > dmax)) {
                mid = i;
                dmax = abs(d[i+1] - d[i]);
            }
        }
        if (dmax % 2 == 0) d[mid+1] = d[mid] = dmax/2;
        else if (d[mid+2] > d[mid-1]) {
            d[mid+1] =
        }
    }
}