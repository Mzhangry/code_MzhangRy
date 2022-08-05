// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int f[1000010], n;
    f[1] = 1;
    f[2] = 1;
    for (int i=3;i<=1000000;i++) {
        f[i] = (2*f[i-1] + 3*f[i-2]) % 10007;
    }
    cin >> n;
    int x;
    for (int i=0;i<n;i++) {
        cin >> x;
        cout << f[x] << endl;
    }
}