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

const int mod = 1000000007;
vector<int> s;
void moplus (int &a, int num) {
    a = (a+num) % mod;
}
int main() {
    int mx; cin >> mx;
    for (int i=1;i<=mx;i++) {
        vector<int> num;
        int n = i;
        while (n) {
            if (n%10 == 2 || n%10 == 0 || n%10 == 3) num.push_back(n % 10);
            n /= 10;
        }
        for (int j=num.size() - 1;j>=0;j--) {
            s.push_back(num[j]);
        }
    }
    vector<int> f3(s.size() + 10), f23(s.size() + 10), f023(s.size() + 10), f2023(s.size() + 10);
    for (int i=s.size()-1;i>=0;i--) {
        f3[i] = f3[i+1], f23[i] = f23[i+1], f023[i] = f023[i+1], f2023[i] = f2023[i+1];
        if (s[i] == 3) moplus(f3[i], 1);
        else if (s[i] == 2) {
            moplus(f23[i], f3[i+1]);
            moplus(f2023[i], f023[i+1]);
        } 
        else if (s[i] == 0) moplus(f023[i], f23[i+1]);
    }
    cout << f2023[0] << endl;
}