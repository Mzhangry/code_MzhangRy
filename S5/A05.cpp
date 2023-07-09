// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a;
vector<bool> t;
int main() {
    while (1) {
        cin >> a;
        if (!a) return 0;
        t.clear();
        while (a>0) {
            t.push_back(a%2);
            a = a>>1;
        }
        int len = t.size();
        bool all_0 = true, all_1 = true;
        for (int i=0;i<len;i++) {
            if (t[i] == 0) all_1 = false;
            else if (i != len-1) all_0 = false;
        }
        if (all_1 || all_0) {
            t[len-1] = false; 
            t.push_back(1); 
        } else {
            int i;
            for (i=len-2;i>=0;i--) {
                if (t[i] == 1 && t[i+1] == 0) {
                    swap(t[i], t[i+1]);
                    break;
                }
            }
            int cnt = 0;
            for (int j=0;j<i;j++) if (t[j] == 1) cnt++;
            for (int j=0;j<cnt;j++) t[j] = 1;
            for (int j=cnt;j<i;j++) t[j] = 0;
        }
        len = t.size();
        int d = 1, ans = 0;
        for (int i=0;i<len;i++) {
            ans += t[i]*d;
            d *= 2;
        }
        cout << ans << endl;
    }
}