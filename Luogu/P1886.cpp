// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

deque<int> q;
int n, k;
int main() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        while (!q.empty() && a[i] <= a[q.back()]) q.pop_back();
        q.push_back(i);
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    cout << endl;
    while (!q.empty()) q.pop_back();
    for (int i=0;i<n;i++) {
        while (!q.empty() && a[i] >= a[q.back()]) q.pop_back();
        q.push_back(i);
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        if (i >= k - 1) cout << a[q.front()] << ' ';
    }
    cout << endl;
}