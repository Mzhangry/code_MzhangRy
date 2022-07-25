// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int aa=0,ab=0,ac=0;
    for (int a1 = n;a1>=0;a1--) {
        for (int a2 = n;a2>=0;a2--) {
            if ((a1 + a2) % 2 != 0) continue;
            for (int a3 = n;a3 >= 0;a3--) {
                if ((a2 + a3 )% 3 != 0 || (a1+a2+a3) % 5 != 0) continue;
                if (a1+a2+a3 > aa+ab+ac) {
                    aa = a1;
                    ab = a2;
                    ac = a3;
                }
            }
        }
    }
    cout << aa+ab+ac << endl;
}