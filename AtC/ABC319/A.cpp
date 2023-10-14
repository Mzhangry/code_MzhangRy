// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, int> m = {{"tourist", 3858}, 
{"ksun48", 3679}, 
{"Benq", 3658},
{"Um_nik", 3648},
{"apiad", 3638},
{"Stonefeang", 3630},
{"ecnerwala", 3613},
{"mnbvmar", 3555},
{"newbiedmy", 3516},
{"semiexp", 3481}};
int main() {
    string s; cin >> s;
    cout << m[s] << endl;
}