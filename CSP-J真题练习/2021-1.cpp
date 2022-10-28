// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int sum = n;
    while (sum < l) sum += n;
    if (sum - 1 < r) cout << n - 1;
    else cout << r - sum + n;
}