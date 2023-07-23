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

string s;
int n;
bool a, b, c;
int main() {
    cin >> n >> s;
    for (int i=0;i<n;i++) {
        if (s[i] == 'A') a = true;
        else if (s[i] == 'B') b = true;
        else c = true;
        if (a && b && c) {
            cout << i+1 << endl;
            return 0;
        }
    }
}