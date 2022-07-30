// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, num[15];
bool used[15]; // 0
void f(int k) {
    if (k == n+1) {
        for (int i=1;i<=n;i++) {
            cout << num[i];
        }
        cout << endl;
        return;
    }
    for (int i=1;i<=n;i++) {
        if (used[i]) continue;
        num[k] = i;
        used[i] = true;
        f(k+1);
        used[i] = false;
    }
}
int main() {
    cin >> n;
    f(1);
}