// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

string s;
char op;
string a, b, c;
int aa, bb, cc;
int ind = 0;
void abc (string& s1) {
    if (s[ind] == '?') {
        for (;ind < s.length() && s[ind] == '?';ind++);
    } else {
        for (;ind < s.length() && s[ind] >= '0' && s[ind] <= '9';ind++) {
            s1 += s[ind]; 
        }
    }
}
void change (string s1, int& a) {
    if (!(s1 == "")) {
        int len = s1.length();
        for (int i=0;i<len;i++) {
            a += s1[i] - '0';
            a *= 10;
        }
        a /= 10;
    } 
}
int solvea() {
    if (op == '+') return cc - bb;
    else if (op == '-') return cc + bb;
    else if (op == '*') return cc / bb;
    else if (op == '/') return cc * bb;
}
int solveb() {
    if (op == '+') return cc - aa;
    else if (op == '-') return aa - cc;
    else if (op == '*') return cc / aa;
    else if (op == '/') return aa / cc;
}
int main() {
    cin >> s;
    abc (a);
    change (a, aa);
    op = s[ind++];
    abc (b);
    change (b, bb);
    ind++;
    abc (c);
    change (c, cc);
    if (op == '?') {
        if (aa + bb == cc) cout << '+';
        else if (aa - bb == cc) cout << '-';
        else if (aa * bb == cc) cout << '*';
        else cout << '/';
    } else {
        if (!aa) cout << solvea();
        else if (!bb) cout << solveb();
        else {
            if (op == '+') cout << aa + bb;
            else if (op == '-') cout << aa - bb;
            else if (op == '*') cout << aa * bb;
            else cout << aa / bb;
        }
    }
}