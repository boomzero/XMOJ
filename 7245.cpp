#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
    long long w, d;
    cin >> w >> d;
    for (long long a = 1; a <= d; ++a) {
        long long i = d - a + 1;
        if (a == d) cout << w / (i * i) << endl;
        w -= w / (i * i);
    }
    return 0;
}
