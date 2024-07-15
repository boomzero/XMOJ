#include <bits/stdc++.h>

using namespace std;

string push(string in) {
    in.push_back(in[0]);
    in.erase(in.begin());
    return in;
}

bool ir(string in) {
    string r = in;
    reverse(r.begin(), r.end());
    return r == in;
}

int main() {
    string a, ba;
    cin >> a;
    ba = a;
    if (ir(a)) {
        cout << 0 << endl << a << endl;
        return 0;
    }
    int ans = 0;
    a = push(a);
    ans++;
    while (a != ba) {
        if (ir(a)) {
            cout << ans << endl << a << endl;
            return 0;
        }
        a = push(a);
        ans++;
    }
    cout << -1 << endl;
    return 0;
}

