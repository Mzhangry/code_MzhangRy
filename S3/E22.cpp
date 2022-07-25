// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n1,n2,n3,n4,n5, k, a,b,c,d,e;
    cin >> k >> n1 >> n2 >> n3 >> n4 >> n5;
    k *= 100;
    for (int i=1;i<k;i++) { //i 井深
        for (a=1;a<2000;a++) {
            b = i - a*n1;
            c = i - b*n2;
            d = i - c*n3;
            e = i - d*n4;
            if (e*n5+a == i
            && b>0 && c>0 && d>0 && e>0
            && a!=b && a!=c && a!=d && a!=e
            && b!=c && b!=d && b!=e
            && c!=d && c!=e
            && d!=e) {
                cout << i << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
                return 0;
            }
        }
    }
    cout << "not found";
}