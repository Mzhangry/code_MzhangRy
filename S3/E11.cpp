// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, zhi[20005],num = 0;
    cin >> n;
    for (int i=2;i<n;i++) {
        bool flag = true;
        for (int j=2;j*j<=i;j++) {
            if (i%j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            zhi[num] = i;
            num++;
        }
    }
    for (int i=0;i<num;i++) {
        for (int j=i;j<num;j++) {
            for (int k=j;k<num;k++) {
                if (zhi[i] + zhi[j] + zhi[k] == n) {
                    cout << zhi[i] << ' ' << zhi[j] << ' ' << zhi[k] << endl;
                    return 0;
                }
            }
        }
    }
}