// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int di = 1e9 + 7;
int e[200005];
int mut = 1;
int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        char op; cin >> op;
        if (op == '+') {
            int ind, num; cin >> ind >> num;
            e[ind] = (e[ind] + num) % di;
        } else {
            int num; cin >> num;
            mut = (mut * num) % di;
        }
    }
    for (int i=1;i<=n;i++) {
        cout << e[i] << ' ' << mut << endl;
        long long d = (e[i] * mut) % di;
        cout << d << ' ';
    }
}