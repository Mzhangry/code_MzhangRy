// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[105];
    for (int i=0;i<n;i++) cin >> a[i];
    sort (a, a+n);
    int i;
    for (i=0;a[i] == 0;i++);
    cout << a[i];
    for (int j=0;j<i;j++) cout << 0;
    for (int j=i+1;j<n;j++) cout << a[j];
}