#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        sum += tmp - 1;
    }
    cout << sum << endl;
    return 0;
}

