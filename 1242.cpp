#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> s;
    string t;
    while (cin >> t) {
        s.insert(t);
    }
    for (auto i: s) {
        cout << i << endl;
    }
    return 0;
}

