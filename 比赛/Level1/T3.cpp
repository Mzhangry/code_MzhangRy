// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    char c;
    cin >> c;
    if ((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) cout << "YES";
    else cout << "NO";
}