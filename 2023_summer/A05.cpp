// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[500005];
        for (int i=0;i<n;i++) cin >> a[i];
        int c1 = a[1] - a[0], c2 = a[n-1] - a[n-2];
        int cn1 = 0, cn2 = 0;
        int i = 0;
        while (1) {
            if (i == n) break;
            if (a[i+1] - a[i] == c1) cn1++;
            else break;
            i++;
        }
        i = n-1;
        while (1) {
            if (i == 0) break;
            if (a[i] - a[i-1] == c2) cn2++;
            else break;
            i--;
        }
        if (cn1 + cn2 >= n-2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}