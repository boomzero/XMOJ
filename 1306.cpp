#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, a, b;
    getline(cin, s);
    cin >> a >> b;
    a.insert(a.begin(), ' ');
    a.push_back(' ');
    b.insert(b.begin(), ' ');
    b.push_back(' ');
    int pos;
    s.insert(s.begin(),' ');
    s.push_back(' ');
    while (true) {
        pos = s.find(a);
        if (pos == -1) break;
        s.replace(pos, a.length(), b);
    }
    s.pop_back();
    s.erase(s.begin());
    cout << s << endl;
    return 0;
}

