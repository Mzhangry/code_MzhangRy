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

ll a, b;
int cnt[10], numa, numb;
int main() {
    cin >> a >> b;
    while (a > 0) {
        cnt[a % 10]++;
        a /= 10;
        numa++;
    }
    vector<int> bb;
    while (b > 0) {
        bb.push_back(b % 10);
        b /= 10;
        numb++;
    }
    if (numa < numb) {
        for (int i=9;i>=0;i--) {
            for (int k=0;k<cnt[i];k++) {
                cout << i;
            }
        }
        cout << endl;
    } else {
        vector<int> ans;
        bool ok = true;
        if (cnt[bb[bb.size()-1]]) {
            ans.push_back(bb[bb.size()-1]);
            int cop[10]; memcpy (cop, cnt, sizeof(cop));
            cop[bb[bb.size()-1]] --;
            for (int k=bb.size()-2;k>=0;k--) {
                bool flag = false; int num = -1;
                for (int i=bb[k];i>=0;i--) {
                    if (cop[i]) {
                        cop[i]--;
                        ans.push_back(i);
                        flag = true; num = i;
                        break;
                    }
                }
                if (!flag) {
                    ok = false;
                    break;
                }
                if (num != bb[k]) {
                    for (int i=9;i>=0;i--) {
                        for (int j=0;j<cop[i];j++) {
                            ans.push_back(i);
                        }
                    }
                    break;
                }
            }
        } else ok = false;
        if (ok) {
            for (int n : ans) cout << n;
            cout << endl;
        } else {
            for (int i=bb[bb.size()-1];i>=0;i--) {
                if (cnt[i]) {
                    cout << i; cnt[i]--;
                    for (int j=9;j>=0;j--) {
                        for (int k=0;k<cnt[j];k++) {
                            cout << j;
                        }
                    }       
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}