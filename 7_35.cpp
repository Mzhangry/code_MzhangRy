// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

void out (char a, char b, bool n, int p1, int num) {
    if (p1 == 2) {
        if (a >= 'a' && a <= 'z') a = a - 'a' + 'A';
        if (b >= 'a' && b <= 'z') b = b - 'a' + 'A';
    }
    if (p1 == 3) {
        for (int i=a+1;i<=b-1;i++) {
            for (int j=0;j<num;j++) cout << '*';
        }
    } else {
        if (n) {
            for (int i=b-1;i>=a+1;i--) {
                for (int j=0;j<num;j++) cout << char(i);
            }
        } else {
            for (int i=a+1;i<=b-1;i++) {
                for (int j=0;j<num;j++) cout << char(i);
            }
        }
    }
}
int main() {
    int p1, p2 ,p3;
    cin >> p1 >> p2 >> p3;
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i] == '-' 
        && s[i-1] < s[i+1] 
        && ((s[i-1] >= '0' && s[i-1] <= '9' && s[i+1] >= '0' && s[i+1] <= '9')
        || (s[i-1] >= 'a' && s[i-1] <= 'z' && s[i+1] >= 'a' && s[i+1] <= 'z'))) {
            out(s[i-1], s[i+1], p3==2, p1, p2);
        } else {
            cout << s[i];
        }
    }
}