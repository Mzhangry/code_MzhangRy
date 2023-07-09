// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int sum[300];
int main() {
    freopen ("d1.out", "r", stdin);
    int a;
    int i=1;
    while (1) {
        cin >> a;
        if (a == -1) {
            i++;
            continue;
            
        } else if (a == -2) 
            break;
        sum[i] += a;
    }
    sort(sum+1, sum+i, greater<int>());
    cout << sum[1] + sum[2] + sum[3];
}