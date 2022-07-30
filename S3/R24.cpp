// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int pell (int a) {
    if (a == 1) return 1;
    if (a == 2) return 2;
    return (2*pell(a-1) + pell(a-2)) % 32767; 
}
int main() {
    int n, k;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> k;
        cout << pell(k) << endl;
    }
}