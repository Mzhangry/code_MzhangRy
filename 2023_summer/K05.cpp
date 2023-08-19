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

int n, m;
string s;
int main() {
    cin >> n >> s >> m;
    int len = s.length();
    vector<int> f(len+1, 1e9), ques(len+1); f[0] = 0;
    vector< vector<int> > cnt (len+1, vector<int> (2));
    for (int i=1;i<=len;i++) {
        if (s[i-1] != 'a') cnt[i][1] = cnt[i-1][0] + 1;
        if (s[i-1] != 'b') cnt[i][0] = cnt[i-1][1] + 1;
        ques[i] = ques[i-1];
        if (s[i-1] == '?') ques[i]++;
    }
    vector<int> now(len+1, 0);
    for (int i=1;i<=len;i++) {
        now[i] = now[i-1]; f[i] = f[i-1];
        if (cnt[i][m % 2 == 0] >= m) {
            if (now[i-m] + 1 == now[i-1]) f[i] = min(f[i-1], f[i-m] + ques[i] - ques[i-m]);
            else {f[i] = f[i-m] + ques[i] - ques[i-m]; now[i]++;}
        }
    }
    // cout << now[n] << endl;
    if (now[n] == 0) cout << 0 << endl;
    else cout << f[n] << endl;
}