#include <bits/stdc++.h>

using namespace std;
int n, k, q;
int ans = 0, stackSize = 0;

void dfs(int sn) {
    stackSize++;
    n -= sn;
    if (n < 0 || stackSize > k) {
        n += sn;
        stackSize--;
        return;
    }
    if (n == 0) {
        if (stackSize == k)
            ans++;
        n += sn;
        stackSize--;
        return;
    }
    if (stackSize == k) {
        n += sn;
        stackSize--;
        return;
    }
    for (int i = sn; i <= n / (k - stackSize); ++i) {
        dfs(i);
    }
    n += sn;
    stackSize--;
}

int main() {
    cin >> n >> k;
    q = n / k;
    for (int i = 1; i <= n / k; ++i) {
        dfs(i);
    }
    cout << ans << endl;
    return 0;
}
