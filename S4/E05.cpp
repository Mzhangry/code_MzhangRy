// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool a[10005][105]; // 表示前i个num中 是否 能达成模k余j
int d[10005];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> d[i];
    a[0][0] = true;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<k;j++) {
            if (a[i-1][(j+k-d[i]%k)%k] == true || a[i-1][(j+k+d[i]%k)%k] == true) a[i][j] = true;
        }
    }
    if (a[n][0]) cout << "Divisible";
    else cout << "Not divisible";
}