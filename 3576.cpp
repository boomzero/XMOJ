#include <bits/stdc++.h>

using namespace std;
int p, curr = 0;
bool val = false;

void dfs(int c) {
    if (val) return;
    if (c == 0) curr += 4;
    else curr += 7;
    if (curr > p) {
        if (c == 0) curr -= 4;
        else curr -= 7;
        return;
    }
    if (curr == p) {
        val = true;
        return;
    }
    for (int i = 0; i <= 1; ++i) {
        dfs(i);
        if (val) return;
    }
    if (c == 0) curr -= 4;
    else curr -= 7;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> p;
    for (int i = 0; i <= 1; ++i) {
        dfs(i);
    }
    if (val) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}


