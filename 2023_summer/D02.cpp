// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n;
map<string, int> year; 
map<string, int> person;
map<string, string> py;
string s[105][8]; // 0nameA 3pos 4year 7nameB
int main() {
    year.insert(make_pair(string("Ox"), 0));
    year.insert(make_pair(string("Tiger"), 1));
    year.insert(make_pair(string("Rabbit"), 2));
    year.insert(make_pair(string("Dragon"), 3));
    year.insert(make_pair(string("Snake"), 4));
    year.insert(make_pair(string("Horse"), 5));
    year.insert(make_pair(string("Goat"), 6));
    year.insert(make_pair(string("Monkey"), 7));
    year.insert(make_pair(string("Rooster"), 8));
    year.insert(make_pair(string("Dog"), 9));
    year.insert(make_pair(string("Pig"), 10));
    year.insert(make_pair(string("Rat"), 11));
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<8;j++) {
            cin >> s[i][j];
        }
    }
    person.insert(make_pair(string("Bessie"), 0));
    py.insert(make_pair(string("Bessie"), "Ox"));
    for (int i=0;i<n;i++) {
        if (s[i][3] == "next") {
            if (year[s[i][4]] > year[py[s[i][7]]]) person[s[i][0]] = person[s[i][7]] + year[s[i][4]] - year[py[s[i][7]]];
            else person[s[i][0]] = person[s[i][7]] + year[s[i][4]] + 12 - year[py[s[i][7]]];
        } else {
            if (year[s[i][4]] < year[py[s[i][7]]]) person[s[i][0]] = person[s[i][7]] - (year[py[s[i][7]]] - year[s[i][4]]);
            else person[s[i][0]] = person[s[i][7]] - (year[py[s[i][7]]] + 12 - year[s[i][4]]);
        }
        py.insert(make_pair(s[i][0], s[i][4]));
    }
    cout << abs (person[string("Elsie")]);
}