// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

long long pell (int k) {
    if (k == 1) return 1;
    if (k == 2) return 2;
    return pell(k-1) * 2 + pell(k-2);
}
int main() {
    int a,n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        cout << pell(a) % 32767 << endl;
    }
}