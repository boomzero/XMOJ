#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout);
    int n;
    cin >> n;
    long long tot = 0;
    for (int i = 1; i <= n; ++i) {
        string st, end;
        cin >> st >> end;
        int h1 = stoi(st.substr(0, st.find(':'))), h2 = stoi(end.substr(0, end.find(':'))), m1 = stoi(
                st.substr(st.find(':') + 1)), m2 = stoi(end.substr(end.find(':') + 1));
        if (h1 == h2) {
            if (m2 < m1) {
                tot += 24 * 60;
            }
            tot += m2 - m1;
        } else {
            int dt = 0;
            dt += 60 - m1;
            dt += m2;
            dt += (h2 - h1 - 1) * 60;
            if (dt < 0) {
                dt = 24 * 60 + dt;
            }
            tot += dt;
        }
    }
    cout << tot << endl;
    return 0;
}

