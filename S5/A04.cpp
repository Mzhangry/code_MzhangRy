// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int main() {
    cin >> t;
    while (t--) {
        int k;
        string s;
        cin >> s >> k;
        int cnt = 0, m = s.length();
        for (int i = 0, j = 1;i < m-1 && cnt < k;) {
            if (s[i] > s[j]) {
                s[i] = 0;
                cnt ++;
                i--;
            } else {
                i = j;
                j++;
            }
        }
        for (int i=0;i < m - k + cnt;i++) {
            if (s[i] == 0) continue;
            cout << s[i];
        }
        cout << endl;
    }
}