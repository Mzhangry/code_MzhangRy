// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int a, b;
ll k;
ll sum[35][35];

string culculate(int a, int b, ll k) {
    if (a == 0 && b == 0) return "";
    if (a == 0 || k > sum[a-1][b]) return 'b' + culculate(a, b-1, k - sum[max(0, a-1)][b]);
    else return 'a' + culculate(a-1, b, k);
}

int main() {
    cin >> a >> b >> k;
    for (int i=0;i<=a;i++) sum[i][0] = 1;
    for (int j=0;j<=b;j++) sum[0][j] = 1;
    for (int i=1;i<=a;i++) for (int j=1;j<=b;j++) {
        sum[i][j] = sum[i-1][j] + sum[i][j-1];
    }
    cout << culculate(a, b, k) << endl;
}   