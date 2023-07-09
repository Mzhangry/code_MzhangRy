// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int f[205][205];
int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        int len1 = s1.length(), len2 = s2.length();
        for (int i=0;i<len1;i++) for (int j=0;j<len2;j++) f[i][j] = 0;
        if (s1[0] == s2[0]) f[0][0] = 1;
        else if (s1[0] == s2[1]) f[0][1] = 1;
        else if (s1[1] == s2[0]) f[1][0] = 1;
        for (int i=1;i<len1;i++) {
            for (int j=1;j<len2;j++) {
                if (s1[i] == s2[j]) f[i][j] = f[i-1][j-1] + 1;
                else f[i][j] = max(f[i-1][j], f[i][j-1]);
            }
        }
        cout << f[len1-1][len2-1] << endl;
    }
}