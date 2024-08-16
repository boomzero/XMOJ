#include <bits/stdc++.h>

using namespace std;
multiset<int> bag;
int fac = 1;

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int m;
    cin >> m;
    int tot = 0;
    for (int i = 0;; ++i) {
        tot += fac;
        if (tot > m) {
            tot -= fac;
            break;
        }
        bag.insert(fac);
        fac *= 2;
    }
    if (m - tot > 0) {
        int val = m - tot;
        if (val != 0)
            bag.insert(val);
    }
    cout << bag.size() << endl;
    for (int i: bag) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
