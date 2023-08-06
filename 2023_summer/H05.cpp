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

int t, m;
int num;
bool exi[105];
int st[105], ed[105];
int main() {
    cin >> t >> m;
    vector<int> e(m+1);
    e[0] = 1e9;
    while (t--) {
        string s; cin >> s;
        if (s == "alloc") {
            ll n; cin >> n;
            bool flag = false;
            for (int i=1;i<=m;i++) if (!e[i]) {
                int j=i;
                for (;j<=m && !e[j] && j-i+1<=n;j++);
                if ((--j)-i+1 == n) {
                    num++;
                    for (int k=i;k<=j;k++) {
                        e[k] = num;
                    }
                    exi[num] = true;
                    st[num] = i; ed[num] = j;
                    flag = true;
                    break;
                } else {
                    i = j;
                }
            }
            if (flag) cout << num << endl;
            else cout << "NULL" << endl;
        } else if (s == "erase") {
            ll x; cin >> x;
            if (x >= 1 && x <= 100 && exi[x]) {
                exi[x] = false;
                for (int i=st[x]; i<=ed[x];i++) {
                    e[i] = 0;
                }
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else {
            int las0 = -1;
            for (int i=1;i<=m;i++){
                if (e[i] == 0 && e[i-1] != 0) las0 = i;
                if (e[i] != 0 && las0 > 0) {
                    int mun = e[i];
                    for (int j=st[mun];j<=ed[mun];j++) e[j] = 0;
                    i = ed[mun];
                    ed[mun] = las0 + (ed[mun] - st[mun]); st[mun] = las0;
                    for (int j=st[mun];j<=ed[mun];j++) e[j] = mun;
                    las0 = ed[mun] + 1;
                }
            }
        }
    }
}