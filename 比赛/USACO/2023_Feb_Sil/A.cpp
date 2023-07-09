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
long long tc, tm1, n;
long long a[105], b[105], c[105];
int main() {
    int t;
    cin >> t; 
    while (t--) {
        cin >> n >> tc >> tm1;
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
        long long moo;
        for (moo = 0;;moo++) {
            bool solve = false;
            for (int subc = 0;subc <= moo;subc ++) {
                long long ttc = tc - subc;
                long long ttm = tm1 - moo + subc;
                if (ttc <= 0 || ttm <= 0) continue;
                bool flag = true;
                for (int i=1;i<=n;i++) {
                    long long tim = a[i] * ttc + b[i] * ttm;
                    if (tim > c[i]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) continue;
                else {
                    solve = true;
                    break;
                }
            }
            if (solve) break;
        }
        cout << moo << endl;
    }
}