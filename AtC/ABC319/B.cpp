// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> choice;
    for (int i=1;i<=9;i++) if (n % i == 0) choice.push_back(i);
    for (int i=0;i<=n;i++) {
        bool flag = false;
        for (int d : choice) {
            if (i % (n/d) == 0) {
                cout << d;
                flag = true;
                break;
            }
        }
        if (!flag) cout << '-';
    }
    cout << endl;
}