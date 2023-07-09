// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int f[205][205];
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        memset (f, 0, sizeof(f));
        int len1 = s1.length(), len2 = s2.length();
        for (int i=1;i<=len1;i++) {
            for (int j=1;j<=len2;j++) {
                if (s1[i-1] == s2[j-1]) f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]));
            }
        }
        cout << f[len1][len2] << endl;
    }
}