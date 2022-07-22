// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int cnt[30];
int main() {
    string s;
    cin >> s;
    int maxn=-1,minn=105;
    for (int i=0;i<s.length();i++) cnt[s[i]-'a']++;
    for (int i=0;i<26;i++) {
        if (cnt[i] > maxn && cnt[i] != 0) maxn = cnt[i];
        if (cnt[i] < minn && cnt[i] != 0) minn = cnt[i];
    }
    int c = maxn - minn;
    bool flag = true;
    if (c < 2) flag = false;
    for (int i=2;i*i<c;i++) if (c % i == 0) flag = false;
    if (flag) cout << "Lucky Word" << endl << c;
    else cout << "No Answer" << endl << 0;
}