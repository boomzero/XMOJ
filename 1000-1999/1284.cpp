#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, m, in[34] = {0}, bin[34] = {0};
        bool ext[34][34] = {false};
        vector<int> g[34];
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0) break;
        bool det = false;
        for (int i = 1; i <= m; i++) {
            char ins[34];
            bool vis[34] = {false};
            scanf("%s", ins);
            if (det) continue;
            if (!ext[ins[0] - 'A' + 1][ins[2] - 'A' + 1]) {
                g[ins[0] - 'A' + 1].emplace_back(ins[2] - 'A' + 1);
                ext[ins[0] - 'A' + 1][ins[2] - 'A' + 1] = true;
                bin[ins[2] - 'A' + 1]++;
            } else continue;
            for (int p = 1; p <= n; p++)
                in[p] = bin[p];
            queue<int> q;
            string s;
            for (int j = 1; j <= n; j++) {
                if (in[j] == 0) q.push(j);
            }
            bool keep = true;
            while (!q.empty()) {
                int c = q.front();
                q.pop();
                vis[c] = true;
                if (s.find(c - 1 + 'A') != string::npos) {
                    continue;
                }
                s.push_back(c - 1 + 'A');
                for (auto v: g[c]) {
                    in[v]--;
                }
                for (int j = 1; j <= n; j++) {
                    if (in[j] == 0 && !vis[j]) {
                        q.push(j);
                        vis[j] = true;
                    }
                }
                if (q.size() > 1) {
                    keep = false;
                }
            }
            if (s.length() < n) {
                cout << "Inconsistency found after " << i << " relations." << endl;
                det = true;
            } else if (keep) {
                cout << "Sorted sequence determined after " << i << " relations: " << s << "." << endl;
                det = true;
            }
        }
        if (!det) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
    }
    return 0;
}

