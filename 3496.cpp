#include <bits/stdc++.h>

using namespace std;
int n, m;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

struct bReq {
    int l, r;

    bReq(int l, int r) : l(l), r(r) {}

    bool operator<(const bReq &rhs) const {
        return r < rhs.r;
    }

    bool operator>(const bReq &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const bReq &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const bReq &rhs) const {
        return !(*this < rhs);
    }
};

vector<bReq> reqs;
int lastBreak = 0;

int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    n = read();
    m = read();
    for (int i = 1; i <= m; ++i) {
        int l, r;
        l = read();
        r = read();
        reqs.emplace_back(l, r);
    }
    int ans = 0;
    sort(reqs.begin(), reqs.end());
    for (auto req: reqs) {
        int l = req.l, r = req.r;
        if (lastBreak >= l) {
            continue;
        }
        lastBreak = r - 1;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
