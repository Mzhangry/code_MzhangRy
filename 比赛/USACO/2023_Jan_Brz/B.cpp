// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int s[25], t[25], c[25];
int a[15], b[15], p[15], money[15];
int opm[15], need[105];
int main() {
    memset(opm, 0, sizeof(opm));
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> s[i] >> t[i] >> c[i];
    for (int i=1;i<=m;i++) cin >> a[i] >> b[i] >> p[i] >> money[i];

    for (int i=1;i<=n;i++) {
        for (int j=s[i];j<=t[i];j++) need[j] = c[i];
    }

    int ans = 2147483640;
    for (opm[1] = 0;opm[1] < 2;opm[1]++) {
        for (opm[2] = 0;opm[2] < 2;opm[2]++) {
            for (opm[3] = 0;opm[3] < 2;opm[3]++) {
                for (opm [4] = 0;opm[4] < 2;opm[4]++) {
                    for (opm[5] = 0;opm[5] < 2;opm[5]++) {
                        for (opm[6] = 0;opm[6] < 2;opm[6]++) {
                            for (opm[7] = 0;opm[7] < 2;opm[7]++) {
                                for (opm[8] = 0;opm[8] < 2;opm[8]++) {
                                    for (opm[9] = 0;opm[9] < 2;opm[9]++) {
                                        for (opm[10] = 0;opm[10] < 2;opm[10]++) {
                                            int sum[105], sum_money = 0;
                                            memset(sum, 0, sizeof(sum));
                                            for (int i=1;i<=m;i++) {
                                                if (opm[i]) {
                                                    for (int j=a[i];j<=b[i];j++) sum[j] += p[i]; //计算总冷却
                                                    sum_money += money[i];
                                                }
                                            }
                                            bool flag = true;
                                            for (int i=1;i<=100;i++) {
                                                if (sum[i] < need[i]) {
                                                    flag = false;
                                                    break;
                                                }
                                            }
                                            // cout << flag << ' ' << sum_money << endl;
                                            if (flag) {
                                                ans = min(ans, sum_money);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}