// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n,a[15];
bool used[15];
void f(int k) {
    if (k == n+1) {
        bool flag = false;
        for (int i=1;i<=n;i++) if (a[i] == 1 && (a[i-1] == 2 || a[i+1] == 2)) 
            flag = true;
        if (flag) {
            for (int i=1;i<=n;i++) cout << a[i];
            cout << endl;
        }
        return;
    }
    for (int i=1;i<=n;i++) {
        if (used[i]) continue;
        a[k] = i;
        used[i] = true;
        f (k+1);
        used[i] = false;
    }
}
int main() {
    cin >> n;
    f(1);
}