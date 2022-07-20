// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,cnt[105],a,maxC;
    cin >> n;
    for (int i=0;i<=100;i++) cnt[i] = 0;
    for (int i=0;i<n;i++) {
        cin >> a;
        cnt[a]++;
    }
    maxC = 100;
    for (int i=99;i>=0;i--) {
        if (cnt[i] > cnt[maxC]) maxC = i;
    }
    cout << maxC << ' ' << cnt[maxC];
    return 0;
}
