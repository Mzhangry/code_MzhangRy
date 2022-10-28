// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a = 0;
    for (int i=1; i<=n; i++) {
        a++;
        if (a%m == 0) a++;
        cout << i << ' ' << a << endl;
    }
}