// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int len;
string s,s1;
bool used[10];
void f(int k) {
    if (k == len) {
        cout << s1 << endl;
        return;
    }
    for (int i=0;i<len;i++) {
        if (! used[i]) {
            s1[k] = s[i];
            used[i] = true;
            f(k+1);
            used[i] = false;
        }
    }
}
int main() {
    cin >> s;
    len = s.length();
    s1 = s;
    f(0);
}