#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * w;
}
unordered_map<int, int> a;
const int maxa = 2e5;
int n;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {int d; cin >> d; a[d]++;}
    int ans = 0;
    for (auto d : a) {
        int cnt = 0;
        for (int i=1; d.first * i <= maxa; i++) {
            if (a.find(d.first*i) != a.end()) cnt += a[d.first * i];
        }
        // for (int i=2; d.first / i > 0; i++) {
        //     if (d.first % i == 0 && a.find(d.first / i)) cnt += a[d.first / i];
        // }
        ans = max (ans, cnt);
    }
    cout << n - ans << endl;
}


