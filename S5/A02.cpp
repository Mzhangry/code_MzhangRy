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
    sort (a, a+n, greater<int>());
    for (int i=0;i<n;i++) cout << a[i];
}