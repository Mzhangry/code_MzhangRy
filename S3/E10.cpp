// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    for (int a=2;a<=100;a++) {
        for (int b=a;b<=100;b++) {
            if (sqrt(a*a+b*b) == int(sqrt(a*a+b*b)) && int(sqrt(a*a+b*b)) <= 100) cout << a << '*' << a << ' ' << '+' << ' ' << b << '*' << b << ' ' << '=' << ' ' << int(sqrt(a*a+b*b)) << '*' << int(sqrt(a*a+b*b)) << endl;
        }
    }
}