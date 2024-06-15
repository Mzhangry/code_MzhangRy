// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x, y;
int gcd (int a, int b) {
    return (a % b == 0) ? b : gcd (b, a % b);
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> x;
        int sum = -1;
        for (int i=1;i<x;i++) {
            int c = gcd(x, i) + i;
            if (c > sum) sum = c, y = i;
        }
        cout << y << endl;
    }
}