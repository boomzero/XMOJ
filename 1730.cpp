#include <bits/stdc++.h>

using namespace std;
int a[1002] = {0};

int f(int n) {
    if (n == 1) return 1;
    int ans = 1;
    for (int i = 1; i <= n / 2; ++i) {
        if (a[i] != 0) {
            ans += a[i];
        } else {
            a[i] = f(i);
            ans += a[i];
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
