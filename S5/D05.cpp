// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[100005], b[100005];
void mergesort (int st, int ed) {
    if (st >= ed) return;
    int mid = (ed + st) >> 1;
    mergesort (st, mid);
    mergesort (mid + 1, ed);
    int left = st, right = mid + 1;
    for (int i=st; i<=ed; i++) {
        if (left > mid || right <= ed && a[left] > a[right]) b[i] = a[right++];
        else b[i] = a[left++];
    }
    for (int i=st;i<=ed;i++) a[i] = b[i];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    mergesort(0, n-1); 
    for (int i=0;i<n;i++) cout << a[i] << ' ';
}