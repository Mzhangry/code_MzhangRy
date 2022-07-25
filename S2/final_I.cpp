// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

void bubble (int a[], int num) {
    for (int i=0;i<num-1;i++) {
        for (int j=0;j<num-1;j++) {
            if (a[j] < a[j+1]) swap (a[j], a[j+1]);
        }
    }
}

void xunhuancout (char f,int a[],int num) {
    for (int i=0;i<num;i++) {
        cout << f;
        if (a[i] <= 10) cout << a[i];
        else if (a[i] == 11) cout << 'J';
        else if (a[i] == 12) cout << 'Q';
        else if (a[i] == 13) cout << 'K';
        else cout << 'A';
        cout << ' ';
    }
}
int main() {
    struct Card
    {
        char f;
        int num;
    };
    string s;
    Card a[15];
    int S[15],H[15],C[15],D[15];
    int numS=0, numH=0, numC=0, numD=0;
    for (int i=0;i<13;i++) { // 读入
        cin >> s;
        a[i].f = s[0];
        if (s.length() == 2 && s[1]>='0' && s[1]<='9') {
            a[i].num = s[1] - '0';
        } else if (s.length() == 3) {
            a[i].num = 10;
        } else {
            if (s[1] == 'J') a[i].num = 11;
            else if (s[1] == 'Q') a[i].num = 12;
            else if (s[1] == 'K') a[i].num = 13;
            else a[i].num = 14;
        }
        if (a[i].f == 'S') {
            S[numS] = a[i].num;
            numS++;
        } else if (a[i].f == 'H') {
            H[numH] = a[i].num;
            numH++;
        } else if (a[i].f == 'C') {
            C[numC] = a[i].num;
            numC++;
        } else {
            D[numD] = a[i].num;
            numD++;
        }
    }
    bubble (S,numS);
    bubble (H,numH);
    bubble (C,numC);
    bubble (D,numD);
    xunhuancout ('S',S,numS);
    xunhuancout ('H',H,numH);
    xunhuancout ('C',C,numC);
    xunhuancout ('D',D,numD);
}