#include <bits/stdc++.h>

#define int long long
using namespace std;
vector<pair<int, int>> cross;

int yb[1006];

int lb(int in) {
    return in & (-in);
}

signed main() {
    int t;
    cin >> t;
    for (int tsk = 0; tsk < t; ++tsk) {
        cross.clear();
        memset(yb, 0, sizeof(yb));
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= k; ++i) {
            int x, y;
            cin >> x >> y;
            cross.emplace_back(x, y);
        }
        int ans = 0;
        sort(cross.begin(), cross.end());
        int cnt = 0;
        for (auto pa: cross) {
            cnt++;
            int x = pa.first, y = pa.second;
            //First, we check how many numbers in yb are lower than y
            //What we are actually calculating is the sum of yb[1] to yb[y]
            int fetch = y, sum = 0;
            while (fetch) {
                sum += yb[fetch];
                fetch -= lb(fetch);
            }
            sum = cnt - sum - 1;
            ans += sum;
            //Now we need to update yb[]
            fetch = y; //reusing this
            while (fetch <= 1005) {
                yb[fetch]++;
                fetch += lb(fetch);
            }
        }
        cout << "Test case " << tsk + 1 << ": " << ans << endl;
    }

    return 0;
}

