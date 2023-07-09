// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int ans;

int dfs (int a, int last) {
    int sum = 1;
    for (int i=a+m;i<n;i++) if (a-last != i-a) {
        sum += dfs(i, a);
    }
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i=0;i<=n;i++) ans += dfs(i, -100);
    cout << ans << endl;    
}