// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int p,e,i, d;
    cin >> p >> e >> i >> d;
    for (int j=1;j<=21252;j++) {
        if ((j+d-p) % 23 == 0 && (j+d-e) % 28 == 0 && (j+d-i) % 33 == 0) {
            cout << j << endl;
            return 0;
        }
    }
}