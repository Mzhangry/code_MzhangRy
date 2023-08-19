// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int extra;
int n;
int main() {
    cin >> n;
    vector<int> f(26, 1); int cnt = 0;
    while (n--) {
        char c; string s; cin >> c >> s;
        vector<bool> possible(26, 0);
        if (c == '!') cnt = 0;
        for (char d : s) {
            if (c == '!') {
                if (f[d - 'a'] == 1) {
                    possible[d-'a'] = true;
                    cnt++;
                }
            } else {
                if (f[d - 'a'] == 1) cnt--;
                f[d - 'a'] = -1;
            }
        }
        if (cnt == 1) break;
        if (c == '!') for (int i=0;i<26;i++) f[i] = possible[i]; 
    }
    for (;n>0;n--) {
        char c; string s; cin >> c >> s;
        if (c == '!') extra++;
        else if (c == '?' && n != 1) extra++;
    }
    cout << extra << endl;
}