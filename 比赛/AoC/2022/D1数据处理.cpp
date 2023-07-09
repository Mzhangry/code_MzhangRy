// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

string s[10005];
int sum = 0;
int main() {
    freopen("d1.in", "r", stdin);
    freopen("d1.out", "w", stdout);
    int i = 1;
    while (1) {
        getline(cin, s[i]);
        if (s[i] == "") {
            s[i] = "-1";
            sum++;
        }
        else if (s[i] == "*") break;
        i++;
    }
    for (int j=1;j<=i;j++) {
        cout << s[j] << endl;
    }
    cout << endl << sum;
}