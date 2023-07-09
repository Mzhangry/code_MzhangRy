// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1010;

void clear (int a[]) {
    memset (a, 0, sizeof(a));
    return;
}
void in (int a[]) {
    clear (a);
    string s;
    cin >> s;
    reverse(begin(s), end(s));
    for (int i=0;i<s.length();i++) a[i] = s[i] - '0';
    return;
}
void sub (int a[], int b[], int c[]) {
    clear (c);

    for (int i=0;i<=maxn - 3;i++) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 10;
            c[i+1] --;
        }
    }
    cout << c[maxn - 2] << ' ';
    if (c[maxn - 2] < 0) {
        cout << '-';
        sub(b, a, c);
        return;
    }
    return;
}
void out (int a[]) {
    int i;
    for (i=maxn - 1;i>=1;i--) {
        if (a[i] > 0) break;
    }
    for (;i>=0;i--) cout << a[i];
    cout << endl;
    return;
}
int a[maxn], b[maxn], c[maxn];
int main() {
    in(a);
    in(b);
    sub (a, b, c);
    out (c);
    return 0;
}