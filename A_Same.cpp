// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    int a; cin >> a;
    for (int i=1;i<n;i++) {
        int b; cin >> b;
        if (a != b) {cout << "No"; return 0;}
    }
    cout << "Yes" << endl;
}