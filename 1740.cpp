#include <bits/stdc++.h>

using namespace std;
int grid[25][25] = {0};
map<int, pair<int, int>> lookup;
priority_queue<int> q;
int et = 0, maxv = 0;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
            lookup[grid[i][j]] = make_pair(i, j);
            q.push(grid[i][j]);
        }
    }
    pair<int, int> curr = {0, 0};
    curr.second = lookup[q.top()].second;
    while (k - et > 0 || q.size() != 0) {
        int t = q.top();
        auto pos = lookup[t];
        q.pop();
        maxv += t;
        k -= abs(pos.first - curr.first);
        k -= abs(pos.second - curr.second);
        k--;
        curr.first = pos.first;
        curr.second = pos.second;
        et = pos.first;
        if (k - et < 0) {
            maxv -= t;
            break;
        }
        if(q.empty()) break;
    }
    cout << maxv << endl;
    return 0;
}

