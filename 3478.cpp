#include <bits/stdc++.h>

using namespace std;
long long a[200001] = {0}, c[200001] = {0}, n;

long long calc(long long b) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(a[i] - (b + i));
    }
    return ans;
}

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
        c[i + 1] = a[i + 1] - i - 1;
    }
    stable_sort(c + 1, c + n + 1);
    cout << min(calc(c[n / 2]), min(calc(c[n / 2 + 1]), calc(c[n / 2 - 1]))) << endl;
    return 0;
}
