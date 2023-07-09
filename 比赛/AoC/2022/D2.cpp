// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    freopen ("d2.in", "r", stdin);
    long long sum = 0;
    char a, b;
    while (1) {
        cin >> a >> b;
        if (a == '*') break;
        if (b == 'X') sum ++;
        else if (b == 'Y') sum += 2;
        else if (b == 'Z') sum += 3;
        if (b - 'X' + 'A' == a) sum += 3;
        else if (a == 'A' && b == 'Y') sum += 6;
        else if (a == 'B' && b == 'Z') sum += 6;
        else if (a == 'C' && b == 'X') sum += 6;
    }
    cout << sum;
}