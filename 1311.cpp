#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, rs, s1, s2;
    getline(cin, s);
    getline(cin, s1);
    getline(cin, s2);
    rs = s;
    reverse(rs.begin(), rs.end());
    reverse(s2.begin(), s2.end());
    int a = s.find(s1), b = rs.find(s2);
    if (a == string::npos || b == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    a++, b++;
    b += s2.length();
    b = (int) s.length() - b;
    if (a + (int) s1.length() >= b) {
        cout << -1 << endl;
        return 0;
    }
    cout << b - a - (int) s1.length() + 2 << endl;
    return 0;
}
