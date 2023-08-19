// Created on iPhone.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> last(k+1, 0), mx(k+1, -1), se(k+1, -1);
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        int c = i-last[a]-1;
        if (c > mx[a]) {
            se[a] = mx[a];
            mx[a] = c;
        } else if (c > se[a]) {
			se[a] = c;
        }
        last[a] = i;
    }
	int ans = 1e9;
    for (int i=1;i<=k;i++) {
        int c = n-last[i];
        if (c > mx[i]) {
            se[i] = mx[i];
            mx[i] = c;
        } else if (c > se[i]) {
            se[i] = c;
        }
    }
    for (int i=1;i<=k;i++) {
        mx[i] = max((mx[i])/2, se[i]);
        ans = min(ans, mx[i]);
    }
    cout << ans << endl;
    return 0;
}