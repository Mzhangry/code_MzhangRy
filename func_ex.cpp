// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int fun1 (int x) {
    return x % 10;
}
bool fun2 (int x, int y) {
    return (x%y==0 || y%x==0);
}
int main() {
    cout << fun2 (3,1);
    return 0;
}