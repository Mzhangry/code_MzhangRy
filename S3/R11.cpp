// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, a[2000][2000];
void f(int k, int yu, int c) {
    if (yu == 0) {
        for (int i=1;i<=k-1;i++) {
            if (a[c][i] == 1) cout << 2;
            else {
                cout << "2(";
                if (a[c][i] > 2) f(1, a[c][i], c+1);
                else cout << a[c][i];
                cout << ')';
            }
            if (i!=k-1) cout << '+';
        }
        return;
    }
    for (int i=0;;i++) {
        if (yu - pow(2, i) < 0) {
            a[c][k] = i-1;
            f(k+1, yu - pow(2, i-1), c);
            return;
        }
    }
}
int main() {
    cin >> n;
    f(1, n, 1);
}
