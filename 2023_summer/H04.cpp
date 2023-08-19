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
vector<int> num;
ll ans = -1;
ll p = 0;

int main() {
    cin >> a >> b;
    while (a > 0) {
        num.push_back(a%10);
        a /= 10;
    }
    
}