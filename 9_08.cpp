// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    double a[305];
    cin >> n;
    int max = 0,min = 0;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        if (a[i] > a[max]) max = i;
        if (a[i] < a[min]) min = i;
    }
    double sum = 0;
    for (int i=0;i<n;i++) {
        if (i!=max && i!=min) sum += a[i];
    }
    if (max == min) sum -= a[max];
    double maxW = 0, av = sum/(n-2);
    for (int i=0;i<n;i++) {
        if (i!=max && i!=min) {
            if (a[i] - av >= 0 && a[i] - av > maxW) {
                maxW = a[i] - av;
            } else if (a[i] - av < 0 && av - a[i] > maxW) {
                maxW = av - a[i];
            }
        }
    }
    cout << fixed << setprecision(2) << av << ' ' << fixed << setprecision(2) << maxW;
}