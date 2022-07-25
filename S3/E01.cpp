// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a;
    cin >> a;
    int max = 0, min = 0;
    for (int i=0;i<=a/2;i++) {
        if ((a-2*i) % 4 != 0) continue;
        int j = (a-2*i) / 4;
        if (i+j > max || max == 0) max = i+j;
        if (i+j < min || min == 0) min = i+j;
    }
    cout << min << ' ' << max << endl;
}