// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int zhuan (int a, int b){
    int re = 0, k = 1;
    while (a>0) {
        if (a%10 >= b) return -1;
        re += a % 10 * k;
        k *= b;
        a /= 10;
    }
    return re;
}
int main() {
    int p, q, r;
    cin >> p >> q >> r;
    for (int b=2;b<=16;b++) {
        int x = zhuan(p, b);
        int y = zhuan(q, b);
        int z = zhuan(r, b);
        if (x != -1 && y != -1 && z != -1
        && x * y == z) {
            cout << b;
            return 0;
        }
    }
    cout << 0;
    return 0;
}