// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m, a = -1;
    cin >> n >> m;
    for (int i=1;i<1000000;i++) {
        if (n%i == 0 && n % (m-i) == 0) {
            a = i;
            break;
        }
    }
    cout << a << endl;
}