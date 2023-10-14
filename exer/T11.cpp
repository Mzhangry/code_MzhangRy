// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f (int a, int mod) {
    if (a == 1) return 1;
    int d = 5*f(a-1, mod) % mod; cout << a << ' ' << d << endl;
    return d;
}
int main() {
    cout << f(23, 23) << endl;
}