#include <bits/stdc++.h>

using namespace std;
map<char, int> m;

int main() {
    string a;
    cin >> a;
    for (char i: a) {
        if (!m.count(i)) m[i] = 0;
        m[i]++;
    }
    for (auto i: m) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}

