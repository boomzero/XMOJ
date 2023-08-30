#include <bits/stdc++.h>
using namespace std;
long long n, val[] = {0, 1, 5, 10, 20, 50, 100}, ans[15] = {0};
int main() {
    cin >> n;
    ans[6] = n / 100;
    n %= 100;
    ans[5] = n / 50;
    n %= 50;
    ans[4] = n / 20;
    n %= 20;
    ans[3] = n / 10;
    n %= 10;
    ans[2] = n / 5;
    n %= 5;
    ans[1] = n / 1;
    n %= 1;
    bool f = true;
    for (int i = 1; i <= 6; ++i) {
        if (!f) cout << " ";
        f = false;
        cout << ans[i];
    }
    return 0;
}
