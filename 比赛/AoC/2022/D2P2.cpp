// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

// 1 2 3 0 3 6 R P S
int f[3][3] = {3, 4, 8,
1, 5, 9,
2, 6, 7};
int main() {
    freopen ("d2.in", "r", stdin);
    long long sum = 0;
    char a, b;
    while (1) {
        cin >> a >> b;
        if (a=='*') break;
        sum += f[a-'A'][b-'X'];
    }
    cout << sum;
}