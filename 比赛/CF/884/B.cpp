// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

//bool pri[200005];
deque<int> a;
int main() {
    // for (int i=2;i<=200000;i++) pri[i] = true;
    // for (int i=2;i<=200000;i++) if (pri[i]) {
    //     int t=1;
    //     while (t++) {
    //         if (i*t > 200000) break;
    //         pri[i*t] = false;
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << 2 << ' ' << 1 << ' ';
        for (int i=3;i<=n;i++) cout << i << ' ';
        cout << endl;
    }
}