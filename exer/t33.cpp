// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n = 5, a;
void solve (int num) {
    if (num == 2022) return;
    a = n*n + 1;
    
    ll sum = 0;
    while (a) sum += a % 10, a /= 10;
    a = sum;
}
int main() {
    solve(1);
    cout << a << endl;
}