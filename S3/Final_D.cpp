// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans[10001], num = 0;
    while (n>0) {
        ans[num] = n%3;
        n /= 3;
        num++;
    }
    for (int i=num-1;i>=0;i--) {
        cout << ans[i];
    }
}