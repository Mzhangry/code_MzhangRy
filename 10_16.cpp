// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    string s,s1;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s1;
        s += s1;
    }
    for (int i=0;i<n*n-1;i++) {
        for (int j=0;j<n*n-1;j++) {
            if (s[j] > s[j+1]) swap(s[j], s[j+1]);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=i*n;j<i*n+n;j++) cout << s[j];
        cout << endl;
    }
}