#include <bits/stdc++.h>

using namespace std;
map<int, vector<pair<int, int>>> prfd;
map<int, string> id;

string fmt(string in) {
    while (in.length() < 6) {
        in.insert(0, "0");
    }
    return in;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int p, y;
        cin >> p >> y;
        prfd[p].emplace_back(y, i + 1);
    }
    for (auto &i: prfd) {
        sort(i.second.begin(), i.second.end());
        int q = 0;
        for (auto j: i.second) {
            q++;
            id[j.second] = fmt(to_string(i.first));
            id[j.second].append(fmt(to_string(q)));
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << id[i] << endl;
    }
    return 0;
}

