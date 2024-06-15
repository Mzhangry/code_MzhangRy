// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int main() {
    cin >> t;
    while (t--) {
        int n, m;
        string s1, s2;
        cin >> n >> m;
        cin >> s1 >> s2;
        int i1 = 0, i2 = 0;
        while (i1 < n) {
            bool flag = false;
            while (i2 < m) {
                if (s1[i1] == s2[i2]) {
                    flag = true; i2++; break;
                } i2++;
            }
            if (!flag) break;
            i1++;
        }
        cout << i1 << endl;
    }
}