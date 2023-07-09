// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int e[200005], d[200005]; // e存储下标为i的球 d存储i球存储在e的下标
int main() {
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;i++) e[i] = d[i] = i;
    while (q--) {
        int num;
        cin >> num;
        int ind = d[num];
        if (ind == n) {
            swap(e[ind], e[ind-1]);
            d[e[ind]] = ind;
            d[e[ind-1]] = ind-1;
        } else {
            swap(e[ind], e[ind+1]);
            d[e[ind]] = ind;
            d[e[ind+1]] = ind+1;
        }
    }
    for (int i=1;i<=n;i++) cout << e[i] << ' ';
}