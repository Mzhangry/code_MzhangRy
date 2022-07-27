// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a1, a2, a3, a5, a10, a20;
    cin >> a1 >> a2 >> a3 >> a5 >> a10 >> a20;
    int ans = 0;
    for (int i=1;i<=1000;i++) {
        bool flag = false;
        for (int m20=0;m20<=a20;m20++) {
            for (int m10=0;m10<=a10;m10++) {
                for (int m5=0;m5<=a5;m5++) {
                    for (int m3=0;m3<=a3;m3++) {
                        for (int m2=0;m2<=a2;m2++) {
                            for (int m1=0;m1<=a1;m1++) {
                                if (1*m1+2*m2+3*m3+5*m5+10*m10+20*m20 == i) {
                                    ans++;
                                    flag = true;
                                    break;
                                }
                                if (m1>1000) break;
                            }
                            if (flag) break;
                            if (m2 > 500) break;
                        }
                        if (flag) break;
                        if (m3 > 334) break;
                    }
                    if (flag) break;
                    if (m5 > 200) break;
                }
                if (flag) break;
                if (m10 > 100) break;
            }
            if (flag) break;
            if (m20 > 20) break;
        }
    }
    cout << "Total=" << ans;
}