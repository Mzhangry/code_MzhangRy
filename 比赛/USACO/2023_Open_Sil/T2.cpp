// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

string s[100005];
vector<int> a;
int main() {
    int c, n;
    cin >> c >> n;
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }
    for (int i=0;i<n;i++) {
        int ans = 0;
        a.clear();
        for (int j=0;j<n;j++) a.push_back(j);
        for (int k=0;k<c;k++) {
            bool flag = false;
            int num = a.size();
            for (int j=0;j<num;j++) {
                a.pop_back();
                if (s[i][k] != s[j][k]) {
                    flag = true;

                }
            }
        }
    }
}