#include <bits/stdc++.h>

using namespace std;
int a[25] = {0}, cans = 0, mans = numeric_limits<int>::max();
bool vis[25] = {false};

void dfs(int n, bool f) {
    vis[n] = true;
    if (f) {
        cans++;
        a[n - 1] = (!a[n - 1]);
        a[n] = (!a[n]);
        a[n + 1] = (!a[n + 1]);
    }
    if (f) {
        if (cans > mans) {
            vis[n] = false;
            cans--;
            a[n - 1] = (!a[n - 1]);
            a[n] = (!a[n]);
            a[n + 1] = (!a[n + 1]);
            return;
        }
    }
    int c = 0;
    for (int i = 1; i <= 20; ++i) {
        if (!a[i]) c++;
    }
    if (c == 20 && n == 20) {
        mans = min(mans, cans);
        vis[n] = false;
        if (f) {
            cans--;
            a[n - 1] = (!a[n - 1]);
            a[n] = (!a[n]);
            a[n + 1] = (!a[n + 1]);
        }
        return;
    } else if (n == 20) {
        vis[n] = false;
        if (f) {
            cans--;
            a[n - 1] = (!a[n - 1]);
            a[n] = (!a[n]);
            a[n + 1] = (!a[n + 1]);
        }
        return;
    }
    dfs(n + 1, true);
    dfs(n + 1, false);
    vis[n] = false;
    if (f) {
        cans--;
        a[n - 1] = (!a[n - 1]);
        a[n] = (!a[n]);
        a[n + 1] = (!a[n + 1]);
    }
}

int main() {
    for (int i = 1; i <= 20; ++i) {
        cin >> a[i];
    }
    dfs(1, true);
    dfs(1, false);
    cout << mans << endl;
    return 0;
}



