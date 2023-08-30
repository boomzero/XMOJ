#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> e;
int ans = 0;
void dfs(int op) {
    vector<int> tmp = e;
    e[op] = e[op] - e[op + 1];
    e.erase(e.begin() + op + 1);
    if (e.size() == 2) {
        if (e[1] == m) {
            ans++;
            return;
        } else {
            return;
        }
    }
    for (int i = 1; i < e.size() - 1; ++i) {
        dfs(i);
    }
    e = tmp;
}
int main() {
    cin >> n >> m;
    e.push_back(0);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        e.push_back(temp);
    }
    for (int i = 1; i < e.size() - 1; ++i) {
        dfs(i);
    }
    cout << ans << endl;
    return 0;
}
