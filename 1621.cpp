#include <bits/stdc++.h>
using namespace std;
set <pair<int, int>> pos, pq;
bool check(int x, int y) {
    for (auto i: pos) {
        if (i.first == x || i.second == y) { return false; }
        if (i.first + i.second == x + y) { return false; }
        if (i.first - i.second == x - y) { return false; }
    }
    return true;
}
int ans = 0;
bool first = true;
void dfs(int x, int y) {
    pos.insert({x, y});
    if (x == 8) {
        ans++;
        if (first) {
            first = false;
            pq = pos;
        }
    } else {
        for (int i = 1; i <= 8; ++i) {
            if (check(x + 1, i)) {
                dfs(x + 1, i);
            }
        }
    }
    pos.erase({x, y});
}
int main() {
    for (int i = 1; i <= 8; ++i) {
        if (check(1, i)) {
            dfs(1, i);
        }
    }
    cout << ans << endl;
    for (auto i: pq) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
