// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int tr (int a) {
    return a*a*a;
}
int main() {
    int n;
    cin >> n;
    for (int a=2;a<=n;a++) {
        for (int b=2;b<a;b++) {
            for (int c=b;c<a;c++) {
                for (int d=c;d<a;d++) {
                    if (tr(a) == tr(b) + tr(c) + tr(d)) {
                        cout << "Cube = " << a << ", Triple = (" << b << ',' << c << ',' << d << ')' << endl;
                    }
                }
            }
        }
    }
}