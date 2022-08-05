// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int mina = 60, n;
int main() {
    cin >> n;
    int a7 = n/7;
    while (a7 >= 0) {
        if ((n - 7*a7) % 5 == 0) mina = min(mina, a7 + (n - 7*a7) / 5);
        if ((n - 7*a7) % 2 == 0) mina = min(mina, a7 + (n - 7*a7) / 2);
        a7 --;
    }
    if (mina == 60) cout << -1;
    else cout << mina;
}