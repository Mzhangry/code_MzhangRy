// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int main() {
    cin >> n;
    int div = 0, sum = 1000;
    for (int i=1;i<=n;i++) {
        if (n / i - 1 + i - 1 < sum) {
            sum = n / i - 1 + i - 1;
            div = i;
        }
    }
    cout << div << endl;
    int per = n/div;
    for (int i=1;;i+=per) {
        
        if (i + 2*per - 1 <= n) {
            cout << 2*per << ' ';
            for (int j=i;j<=i+2*per-1;j++) {
                cout << j << ' ';
                cout << endl;
            }
        } else {
            cout << n - i + 1 << ' ';
            for (int j=i;j<=n;j++) cout << j << ' ';
            cout << endl;
            break;
        }
    }

    for (int i=1;i<=per;i++) {
        vector<int> a;
        for (int j=i;j<=n;j+=per) a.push_back (j);
        cout << a.size() << ' ';
        for (int d : a) cout << d << ' ';
        cout << endl;
    }
    string s; cin >> s;
    for (int i=0;i<div;i++) ;
}