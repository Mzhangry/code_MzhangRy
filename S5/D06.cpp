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
long long mergesort (int st, int ed) {
    if (st == ed) return 0;
    int mid = (st + ed) / 2;
    long long ansl = mergesort(st, mid), ansr = mergesort(mid+1, ed);
    long long ansrl = 0; int left = st, right = mid+1;
    for (int i=st;i<=ed;i++) {
        if (right > ed || left <= mid && a[left] < a[right]) {
            b[i] = a[left++];
            ansrl += right - mid - 1;
        } else {
            b[i] = a[right++];
        }
    }
    for (int i=st;i<=ed;i++) a[i] = b[i];
    return ansl + ansr + ansrl;
}
int main() {
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << mergesort (1, n);
}