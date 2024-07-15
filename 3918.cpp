#include <bits/stdc++.h>
using namespace std;

struct ufs {
    int rt[200005], n;

    int find(int t) {
        return rt[t] == t ? t : rt[t] = find(rt[t]);
    }

    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) {
            rt[ra] = rb;
        }
    }

    ufs(int n) {
        for (int i = 1; i <= n; i++) {
            this->rt[i] = i;
        }
        this->n = n;
    }
};

int main() {
    freopen("d.in", "r",stdin);
    freopen("d.out", "w",stdout);
    int n, k, l;
    cin >> n >> k >> l;
    ufs rail(n), road(n);
    for (int i = 1; i <= k; i++) {
        //roads
        int p, q;
        cin >> p >> q;
        road.merge(p, q);
    }
    for (int i = 1; i <= l; i++) {
        //railways
        int r, s;
        cin >> r >> s;
        rail.merge(r, s);
    }
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[make_pair(road.find(i), rail.find(i))]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << mp[make_pair(road.find(i), rail.find(i))];
        if (i != n) cout << ' ';
    }
    cout << endl;
    return 0;
}

