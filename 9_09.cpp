// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int cnt[10005];
int main() {
    int n, max = 0;
    cin >> n;
    int a;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (a > max) max = a;
        cnt[a]++;
    }
    for (int i=0;i<=max;i++) {
        cout << cnt[i] << endl;
    }
}