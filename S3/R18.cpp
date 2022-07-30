// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int num[15];
bool used[15];
void f(int k) {
    if (k == 10) {
        int a = num[1] * 100 + num[2] * 10 + num[3];
        int b = num[4] * 100 + num[5] * 10 + num[6];
        int c = num[7] * 100 + num[8] * 10 + num[9];
        if (a*2 == b && a*3 == c) cout << a << ' ' << b << ' ' << c << endl;
        return;
    }
    for (int i=1;i<=9;i++) {
        if (! used[i]) {
            num[k] = i;
            used[i] = true;
            f(k+1);
            used[i] = false;
        }
    }
}
int main() {
    f(1);
}