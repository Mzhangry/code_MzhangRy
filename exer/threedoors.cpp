// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int sum = 0, correct = 0;
    for (int i=1;i<=100000;i++) {
        sum++;
        int car = (rand() % (3-1+1))+ 1;
        int choose = (rand() % (3-1+1)) + 1;
        if (car == choose) continue;
        if      (car == 1 && choose == 2) choose = 1;
        else if (car == 2 && choose == 1) choose = 2;
        else if (car == 1 && choose == 3) choose = 1;
        else if (car == 3 && choose == 1) choose = 3;
        else if (car == 2 && choose == 3) choose = 3;
        else if (car == 3 && choose == 2) choose = 2;
        if (car == choose) correct++;
    }
    cout << sum << ' ' << correct << endl;
    cout << correct*1.0 / sum;
}