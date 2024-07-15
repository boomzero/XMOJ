#include <bits/stdc++.h>

using namespace std;
map<string, int> c;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        if (!c.count(t)) c[t] = 0;
        c[t]++;
    }
    int sum = 0;
    for (auto const &i: c) {
        if (i.second % 2 != 0) sum++;
        sum += i.second / 2;
    }
    cout << sum << endl;
    return 0;
}
