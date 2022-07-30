// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, a[15];
void f(int k) {
    // 递归从k到n位的数
    // 枚举结束 此时a[1] ~ a[n]是一个完整的幸运数
    if (k == n+1) {
        for (int i=1;i<=n;i++) cout << a[i];
        cout << endl;
        return;
    }
    for (int i=1;i<=3;i++) {
        a[k] = i;
        f(k+1);
    }
}
int main() {
    cin >> n;
    f(1);
    return 0;
}