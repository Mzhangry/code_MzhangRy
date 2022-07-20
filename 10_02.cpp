// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,last = -1,a;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (last > a) {
            cout << "upset";
            return 0;
        }
        last = a;
    }
    cout << "happy";
}