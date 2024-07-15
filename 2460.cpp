#include <bits/stdc++.h>

using namespace std;
int n, r;
bool vis[30] = {false};
int stackSize = 0, a[30];

void dfs(int c) {
    stackSize++;
    vis[c] = true;
    a[stackSize] = c;
    if (stackSize == r) {
        bool first = true;
        for (int i = 1; i <= stackSize; ++i) {
            if (!first) putchar(' ');
            first = false;
            printf("%d", a[i]);
        }
        putchar('\n');
        vis[c] = false;
        stackSize--;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    vis[c] = false;
    stackSize--;
}

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    return 0;
}

