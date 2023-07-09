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
        int n;
        char d;
        cin >> n >> d;
        string s;
        cin >> s;
        bool flag = false;
        for (int i=0;i<n;i++) {
            if (!flag && d > s[i]) {
                cout << d;
                flag = true;
            }
            cout << s[i];
        }
        if (!flag) cout << d;
        cout << endl;
    }
}