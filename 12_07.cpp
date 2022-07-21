// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

void draw(int a, char c) {
    for (int i=0;i<a;i++) cout << c;
    cout << endl;
}
int main() {
    int n,x;
    char c1;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x >> c1;
        draw (x, c1);
    }
}