// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, k, pell[1000010] = {1,1,2};
    cin >> n;
    for (int i=3;i<=1000000;i++) 
        pell[i] = (pell[i-1]*2 + pell[i-2]) % 32767;
    for (int i=0;i<n;i++) {
        cin >> k;
        cout << pell[k] << endl;
    }
}