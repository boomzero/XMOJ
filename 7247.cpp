#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("an.in", "r", stdin);
    freopen("an.out", "w", stdout);
    double a = 4;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a *= 0.75;
    }
    printf("%.10f", a);
    return 0;
}

