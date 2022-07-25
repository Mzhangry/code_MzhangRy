// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool shirunnian(int x) {
    if (x%4 == 0 && x%100 != 0 || x%400 == 0) return true;
    else return false;
} 
int main() {
    int l,r, cnt=0;
    cin >> l >> r;
    for (int i=l;i<=r;i++) if(shirunnian(i)) cnt ++;
    cout << cnt << endl;
    for (int i=l;i<=r;i++) if(shirunnian(i)) cout << i << ' ';
}