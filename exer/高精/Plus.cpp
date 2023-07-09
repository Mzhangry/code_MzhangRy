// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 1002;
void clear(int a[]) {
    memset (a, 0, sizeof(a));
    return;
}
void add(int a[],int b[], int c[]) {
    clear(c);

    for (int i=0;i<=maxn;i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i+1] ++;
            c[i] -= 10;
        }
    }
    return;
}
void out(int a[]) {
    int i;
    for (i=maxn;i>=1;i--) {
        if (a[i] != 0) break;
    }
    for (;i>=0;i--) {
        cout << a[i];
    }
    cout << endl;
    return;
}
string s1, s2;
int a[maxn], b[maxn], c[maxn];
int main() {
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i=0;i<len1;i++) a[i] = s1[i] - '0';
    for (int i=0;i<len2;i++) b[i] = s2[i] - '0';
    add (a, b, c);
    out (c);
    return 0;
}