#include <bits/stdc++.h>

using namespace std;
int m, n;
typedef pair<int, int> gm; ///w,t
vector<gm> games;
bool t[1000] = {false};

bool lcmp(gm a, gm b) { return a > b; }

bool place(int lt) {
    for (int i = lt; i > 0; --i) {
        if (!t[i]) {
            t[i] = true;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> m >> n;
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp[i];
    }
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        games.emplace_back(tp, tmp[i]);
    }
    sort(games.begin(), games.end(), lcmp);
    for (auto i: games) {
        if (!place(i.second)) {
            m -= i.first;
        }
    }
    if (m < 0) {
        cout << 0 << endl;
    } else {
        cout << m << endl;
    }
    return 0;
}

