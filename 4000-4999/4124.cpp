#include <bits/stdc++.h>

using namespace std;
int n, m;
string ndna[505], tdna[505];

bool ok(int x, int y, int k) {
    unordered_set<string> nd, td;
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        string uid;
        uid.push_back(ndna[i][x]);
        uid.push_back(ndna[i][y]);
        uid.push_back(ndna[i][k]);
        nd.insert(uid);
    }
    for (int i = 1; i <= n; i++) {
        string uid;
        uid.push_back(tdna[i][x]);
        uid.push_back(tdna[i][y]);
        uid.push_back(tdna[i][k]);
        td.insert(uid);
    }
    for (const string &i: nd) {
        if (td.count(i)) {
            ans = false;
        }
    }
    return ans;
}

int main() {
    //freopen("dat.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ndna[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> tdna[i];
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                if (i == j || j == k || i == k) continue;
                if (ok(i, j, k)) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
