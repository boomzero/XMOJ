#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> dot;
    map<pair<int, int>, int> dh;
    for (int i = 0; i < n; ++i) {
        int x, y, h;
        cin >> x >> y >> h;
        dot.emplace_back(x, y);
        dh[make_pair(x, y)] = h;
    }
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int h;
            for (auto i: dot) {
                if (dh[i] == 0) continue; //check
                h = max(dh[i] + abs(i.first - cx) + abs(i.second - cy), 0);
                if (h == 0) continue;
                break;
            }
            bool val = true;
            for (auto i: dot) {
                if (dh[i] != max(h - abs(i.first - cx) - abs(i.second - cy), 0)) {
                    val = false;
                    break;
                }
            }
            if (val) {
                cout << cx << " " << cy << " " << h << endl;
                return 0;
            }
        }
    }
    return 0;
}

