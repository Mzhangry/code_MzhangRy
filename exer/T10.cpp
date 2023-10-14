// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define A a[1]
#define B a[2]
#define C a[3]
#define AB a[4]
#define BC a[5]
#define AC a[6]
#define ABC a[7]

int a[10]; // 1A 2B 3C 4AB 5BC 6AC 7ABC
int sum = 0;
void dfs (int k) {
    if (k == 8) {
        if (sum != 28) return;
        if (A != AB+AC+ABC + 1) return;
        for (int i=1;i<=7;i++) cout << a[i] << ' ';
        cout << endl;
        return;
    }
    if (k == 4) if (A != B+C) return;
    if (k == 6) if ((B+BC) != 2*(BC+C)) return;
    
    for (int i=0;i<=28;i++) {
        a[k] = i; sum += i;
        if (sum <= 28) dfs(k+1);
        sum -= i;
    }
}
int main() {
    dfs(1);
}