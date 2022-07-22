// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool hefa (string s,int l, int i) {
    int num = 0;
    if (l == 3) {
        num = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + s[i+2] - '0';
    } else if (l == 2) {
        num = (s[i] - '0') * 10 + s[i+1] - '0';
    } else if (l == 1) {
        num = s[i] - '0';
    } else return false;
    return (num >= 0 && num <= 255);
}
int main() {
    string s;
    int n,p[25];
    cin >> n;
    for (int i=0;i<n;i++) {
        bool flag = true;
        int point = 0;
        cin >> s;
        int len = s.length();
        for (int i=0;i<len;i++) {
            if (s[i] == '.') {
                p[point] = i;
                point++;
                if (s[i+1] == '.' || (s[i+1] == '0' && s[i+2] != '.' && i+2 != len) || i==0 || i==len-1) {
                    flag = false;
                    break;
                }
            }
        }
        if (s[0] == '0' && s[1] != '.') flag = false;
        if (point != 3) flag = false;
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        if (hefa(s,p[0],0) && hefa(s,p[1] - p[0] - 1,p[0]+1) && hefa(s,p[2] - p[1] - 1,p[1]+1) && hefa(s,len-1-p[2],p[2]+1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
