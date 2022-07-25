// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int m, a;
    cin >> m;
    int max = -10001, min = 10001;
    for (int i=0;i<m;i++) {
        cin >> a;
        if (a > max) max = a;
        if (a < min) min = a;
    }
    cout << max - min << endl;
}