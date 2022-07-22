// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    char a[205][205];
    int n, m, d=0; //n行数 m列数
    string s;
    cin >> m >> s;
    n = s.length() / m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            a[i][j] = s[d];
            d++;
        }
        i++;
        if (i==n) break;
        for (int j=m-1;j>=0;j--) {
            a[i][j] = s[d];
            d++;
        }
    }
    for (int j=0;j<m;j++) {
        for (int i=0;i<n;i++) {
            cout << a[i][j];
        }
    }
}