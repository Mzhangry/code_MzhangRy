// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int middle (int a, int b, int c) {
    if (a>b && a<c || a<b && a>c) return a;
    else if (b>a && b<c || b>c && b<a) return b;
    else return c;
}
int main() {
    int a,b,c,d,e,f,g,h,i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    cout << middle(middle(a,b,c),middle(d,e,f),middle(g,h,i));
}