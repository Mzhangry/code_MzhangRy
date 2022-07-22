// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int theNum (int l, int r, string s) {
    if (r - l - 1 == 1) return (s[l+1] - '0');
    else if (r - l - 1 == 2) return ((s[l+1] - '0')*10 + s[l+2] - '0');
    else if (r - l - 1 == 3) return ((s[l+1] - '0')*100 + (s[l+2] - '0')*10 + (s[l+3] - '0')*1);
    else return ((s[l+1] - '0')*1000 +(s[l+2] - '0')*100 + (s[l+3] - '0')*10 + (s[l+4] - '0')*1);
}
int main() {
    int n;
    cin >> n;
    int a[35][105];
    string s;
    int L = -1, R = -1, now[35], max = 0;
    for (int i=1;i<=n;i++) {
        cin >> s;
        now[i] = 0;
        L = -1;
        R = -1;
        while (1) {
            L = R;
            if (L == s.length()) break;
            R++;
            while (R < s.length() && s[R] != ',') R++;
            a[i][now[i]] = theNum(L, R, s);
            now[i] ++;
        }
    }
    int cnt = 1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<now[i];j++) {
            if (a[i][j] > max) {
                max = a[i][j];
                cnt = 1;
            } else if (a[i][j] == max) {
                cnt ++;
            }
        }
    }
    cout << max << endl;
    for (int i=1;i<=n;i++) {
        bool flag = false;
        for (int j=0;j<now[i];j++) {
            if (a[i][j] == max) {
                flag = true;
                cnt --;
            }
        }
        if (flag && cnt != 0) {
            cout << i << ',';
        } else if (flag) {
            cout << i;
        }
    }
}
