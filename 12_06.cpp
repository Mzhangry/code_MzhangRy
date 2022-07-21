// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

void square (int a) {
    for (int i=0;i<a;i++) {
        for (int j=0;j<a;j++) cout << a << ' ';
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) square(i);
}