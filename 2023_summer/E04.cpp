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
ll num;
int k = 0;
int main() {
    cin >> s >> num;
    int len = s.length();
    for (int i=len;i>=1;i--) s[i] = s[i-1];
    ll left = 1, right = len, mid;
    while (right < num) right *= 2;
    while (1) {
        if (right - left + 1 == len) {
            cout << s[num-left+1] << endl;
            return 0;
        }
        mid = (left + right - 1) / 2;
        if (num > mid) {
            left = mid + 1;
            if (num == mid + 1) num = right;
            else num --;
        }
        else right = mid;
    }
}