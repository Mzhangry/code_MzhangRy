// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool used[30];
char a[30],c;
void f(int k) {
    if (k == c-'A'+1+1) {
        for (int i=1;i<=k-1;i++) cout << a[i];
        cout << endl;
        return;
    }
    for (int i='A';i<=c;i++) {
        if (used[i-'A'+1]) continue;
        a[k] = char(i);
        used[i-'A'+1] = true;
        f(k+1);
        used[i-'A'+1] = false;
    }
}
int main() {
    cin >> c;
    f(1);
}