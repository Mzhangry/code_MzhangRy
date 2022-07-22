// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length(), max = 0, now;
    for (int i=0;i<len1;i++) { // 在s1中选择1字符
        for (int j=0;j<len2;j++) { // 在s2中选择1字符
            now = 0;
            for (int k=0;k<min(len1,len2);k++) { // 向后k字符
                if (s1[(i+k)%len1] != s2[(j+k)%len2]) break;
                now ++;
            }
            if (now > max) max = now;
        }
    }
    cout << max;
}