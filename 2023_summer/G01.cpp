// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int n;
bool used[500005], fre[500005];
int main() {
    cin >> n;
    vector<int> a;
    for (int i=0;i<n;i++) {
        int d; cin >> d;
        a.push_back(d);
    }
    sort(a.begin(), a.end(), greater<int>());
    int left = 0, right = n-1, mid;
    for (int i=0;i<n;i++) if (!used[i]) {
        if (left >= n) break;
        for (int j=i+1;j<n;j++) if (!used[j]) {
            used[i] = used[j] = true;
            while (left < right) {
                mid = (left + right) / 2;
                if (a[mid] > a[j]/2) left = mid + 1;
                else right = mid;
            }
            if (a[left] > a[j]/2) {
                left++; break;
            }
            right = n-1;
            while (used[left]) left++;
            used[left] = fre[left] = true;
            left++;
            break;
        }
    }
    ll sum = 0;
    for (int i=0;i<n;i++) if (!fre[i]) sum += a[i];
    cout << sum << endl;
}