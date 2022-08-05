// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, a[15], ans = 0;
int cn[5], sum;
void f(int k) {
    if (k == n+1) {
        if (cn[3] >= cn[2] && cn[2] >= cn[1] && sum %2 == 0) {
            for (int i=1;i<k;i++) 
                cout << a[i];
            cout << endl;
            ans++;
        }
        return;
    }
    for (int i=1;i<=3;i++) {
        if (k>1 && a[k-1] == i) continue;
        a[k] = i;
        cn[i] ++;
        sum += i;
        f(k+1);
        cn[i]--;
        sum -= i;
    }
}
int main() {
    cin >> n;
    f(1);
    cout << ans << endl;
}