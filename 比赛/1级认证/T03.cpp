// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a==b || b==c || a==c) cout << "YES";
    else cout << "NO";
}