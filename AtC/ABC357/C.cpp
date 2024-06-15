// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
int main() {
    cin >> n;
    int d = pow(3, n);
    for (int i=0;i<d;i++) {
        for (int j=0;j<d;j++) {
            bool flag = true;
            int x = i, y = j;
            for (int k=0;k<n;k++) {
                if (x % 3 == 1 && y % 3 == 1) {
                    flag = false;
                    break;
                }
                x /= 3;
                y /= 3;
            }
            cout << (flag ? '#' : '.');

        }
        cout << endl;
    }

}