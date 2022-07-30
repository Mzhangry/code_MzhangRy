// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, a[15];
void f (int k, int yu) {
    if (yu == 0) {
        for (int i=1;i<=k-1;i++) {
            cout << a[i];
            if (i != k-1) cout << '+';
        }
        cout << endl;
        return;
    }
    for (int i=1;i<=yu;i++) {
        a[k] = i;
        f (k+1, yu-i);
    }
}
int main() {
    cin >> n;
    f(1, n);
}