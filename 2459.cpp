#include <bits/stdc++.h>

using namespace std;
int n;
int s[200] = {0}, ans[200] = {0}, stackSize = 0;

void dfs(int sn) {
    stackSize++;
    n -= sn;
    if (n < 0) {
        n += sn;
        stackSize--;
        return;
    }
    ans[stackSize] = sn;
    if (n == 0) {
        bool f = true;
        for (int i = 1; i <= stackSize; ++i) {
            if (!f) cout << '+';
            f = false;
            cout << ans[i];
        }
        cout << endl;
        n += sn;
        stackSize--;
        return;
    }
    for (int i = sn; i <= n; ++i) {
        dfs(i);
    }
    n += sn;
    stackSize--;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    return 0;
}
