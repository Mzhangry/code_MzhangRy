// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

string abc, s;
int main() {
    cin >> abc >> s;
    int cnt = 0;
    for (int i=0;i<s.length();i++) {
        while (abc[cnt % 26] != s[i]) cnt++;
        cnt++;
    }
    cnt--;
    cout << cnt/26+1 << endl;
}