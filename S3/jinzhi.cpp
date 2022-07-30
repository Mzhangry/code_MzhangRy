// 10进制 -> k进制
    // 思路
    // 反复短除取余数，当商0时逆序输出
    int a,k = 8, y[100], num = 0; // k为所转进制
    cin >> a;
    while (a>0) {
        y[num] = a%k;
        num++;
        a /= k;
    }
    for (int i=num-1;i>=0;i--) {
        cout << y[i];
        // 若转为大于10的进制，注意当 y[i] >= 10 时，输出 y[i] - 10 + 'A'
    }
// k进制 -> 10进制
    // 思路
    // 每个数乘系数 (k^(位数-1)) 按照以下算法 每个数刚好乘 位数-1 个 k
    string s;
    int ans = 0, k = 8; // k为待转进制
    cin >> s;
    for (int i=0;i<s.length();i++) {
        ans = ans * k + s[i] - '0';
        // 若由大于10的进制转为10进制，注意当 !(s[i] >= '0' && s[i] <= '9') 时， ans = ans * k + s[i] - 'A' +10
    }
    cout << ans;
// * m进制 -> n进制，且 m^k == n || m == n^k，即可用k位一断 || 一位k写的方法