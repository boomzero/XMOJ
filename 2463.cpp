#include <bits/stdc++.h>

using namespace std;
int n;
int graph[1100][1100] = {{0}};
bool vis[1100] = {false};
bool first = true;

void dfs(int c) {
    vis[c] = true;
    if (!first) putchar('-');
    first = false;
    cout << c;
    for (int i = 1; i <= n; ++i) {
        if (graph[c][i] && !vis[i]) {
            dfs(i);
        }
    }
//    vis[c] = false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }
    dfs(1);
    return 0;
}


