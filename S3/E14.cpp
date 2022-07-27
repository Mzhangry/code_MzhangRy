// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int m;
    cin >> m;
    for (int i=1;i<m/2+1;i++) {
        int sum = 0;
        int j = i;
        while (sum < m) {
            sum += j;
            j++;
        }
        if (sum == m) cout << i << ' ' << j - 1 << endl;
    }
}