// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m;
    long long ansS = 0, ansC = 0;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (i==j)
                ansS += (n-(i-1)) * (m-(j-1));
            else
                ansC += (n-(i-1)) * (m-(j-1));
        }
    }
    cout << ansS << ' ' << ansC;
}