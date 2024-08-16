#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    string in;
    long long k, bt = 0;
    cin >> in >> k;
    for (long long i = 0; i < in.length(); ++i) {
        if (in[i] != '1') {
            break;
        }
        bt++;
    }
    if (k <= in.size() && k <= bt) cout << 1 << endl;
    else {
        for (char i: in) {
            if (i != '1') {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
