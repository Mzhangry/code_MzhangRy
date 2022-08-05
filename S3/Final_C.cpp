// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,id = 1;
    cin >> n;
    for (int a=1;a<n;a++) {
        for (int b=a;b<n;b++) {
            for (int c=b;c<n;c++) {
                if (a*a + b*b == c*c) {
                    cout << id << ':' << ' ' << a << '*' << a << '+' << b << '*' << b << '=' << c << '*' << c << endl;
                    id++;
                }
            }
        }
    }
}