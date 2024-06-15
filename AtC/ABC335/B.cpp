// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int main() {
    cin >> n;
    for (int a=0;a<=n;a++) {
        for (int b=0;b<=n;b++) {
            for (int c=0;c<=n;c++) {
                if (a + b + c <= n) cout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
}