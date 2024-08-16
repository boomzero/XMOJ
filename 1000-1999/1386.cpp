#include <bits/stdc++.h>

using namespace std;
//do this twice. makes sense?
constexpr int mx = 100005;
int gval[mx << 2];
int glazy[mx << 2];

void gpush_up(int rt) {
    gval[rt] = gval[rt * 2] + gval[rt * 2 + 1];
}

void gpush_down(int rt, int l, int r) {
    if (glazy[rt] == 0) {
        //pass the laziness down
        glazy[rt * 2] = 0;
        glazy[rt * 2 + 1] = 0;
        gval[rt * 2] = 0;
        gval[rt * 2 + 1] = 0;
        glazy[rt] = -1;
    } else if (glazy[rt] == 1) {
        //pass the laziness down
        glazy[rt * 2] = 1;
        glazy[rt * 2 + 1] = 1;
        int mid = (l + r) / 2;
        gval[rt * 2] = mid - l + 1;
        gval[rt * 2 + 1] = r - mid;
        glazy[rt] = -1;
    }
}

void gbuild(int rt, int l, int r) {
    if (l == r) {
        gval[rt] = 1;
        return;
    }
    int mid = (l + r) / 2;
    gbuild(rt * 2, l, mid);
    gbuild(rt * 2 + 1, mid + 1, r);
    gpush_up(rt);
}

int gquery(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && qr >= r) {
        return gval[rt];
    }
    gpush_down(rt, l, r);
    int mid = (l + r) / 2;
    return gquery(rt * 2, l, mid, ql, qr) + gquery(rt * 2 + 1, mid + 1, r, ql, qr);
}

void gupd(int rt, int l, int r, int ul, int ur, int cl) {
    if (ul > r || ur < l) {
        return;
    }
    if (ul <= l && ur >= r) {
        if (cl == 0) {
            glazy[rt] = 0;
            gval[rt] = 0;
        } else {
            glazy[rt] = 1;
            gval[rt] = (r - l) + 1;
        }
        return;
    }
    gpush_down(rt, l, r);
    int mid = (l + r) / 2;
    gupd(rt * 2, l, mid, ul, ur, cl);
    gupd(rt * 2 + 1, mid + 1, r, ul, ur, cl);
    gpush_up(rt);
}

int sval[mx << 2];
int slazy[mx << 2];

void spush_up(int rt) {
    sval[rt] = sval[rt * 2] + sval[rt * 2 + 1];
}

void spush_down(int rt, int l, int r) {
    if (slazy[rt] == 0) {
        //pass the laziness down
        slazy[rt * 2] = 0;
        slazy[rt * 2 + 1] = 0;
        sval[rt * 2] = 0;
        sval[rt * 2 + 1] = 0;
        slazy[rt] = -1;
    } else if (slazy[rt] == 1) {
        //pass the laziness down
        slazy[rt * 2] = 1;
        slazy[rt * 2 + 1] = 1;
        int mid = (l + r) / 2;
        sval[rt * 2] = mid - l + 1;
        sval[rt * 2 + 1] = r - mid;
        slazy[rt] = -1;
    }
}

void sbuild(int rt, int l, int r) {
    if (l == r) {
        sval[rt] = 1;
        return;
    }
    int mid = (l + r) / 2;
    sbuild(rt * 2, l, mid);
    sbuild(rt * 2 + 1, mid + 1, r);
    spush_up(rt);
}

int squery(int rt, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && qr >= r) {
        return sval[rt];
    }
    spush_down(rt, l, r);
    int mid = (l + r) / 2;
    return squery(rt * 2, l, mid, ql, qr) + squery(rt * 2 + 1, mid + 1, r, ql, qr);
}

void supd(int rt, int l, int r, int ul, int ur, int cl) {
    if (ul > r || ur < l) {
        return;
    }
    if (ul <= l && ur >= r) {
        if (cl == 0) {
            slazy[rt] = 0;
            sval[rt] = 0;
        } else {
            slazy[rt] = 1;
            sval[rt] = (r - l) + 1;
        }
        return;
    }
    spush_down(rt, l, r);
    int mid = (l + r) / 2;
    supd(rt * 2, l, mid, ul, ur, cl);
    supd(rt * 2 + 1, mid + 1, r, ul, ur, cl);
    spush_up(rt);
}

int main() {
    int tcc;
    cin >> tcc;
    for (int i = 1; i <= tcc; i++) {
        memset(slazy, -1, sizeof(slazy));
        memset(glazy, -1, sizeof(glazy));
        memset(gval, 0, sizeof(gval));
        memset(sval, 0, sizeof(sval));
        int n, q;
        cin >> n >> q;
        sbuild(1, 1, n);
        gbuild(1, 1, n);
        gupd(1, 1, n, 1, n, 0);
        supd(1, 1, n, 1, n, 0);
        for (int j = 1; j <= q; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            switch (z) {
                case 1: {
                    gupd(1, 1, n, x, y, 0);
                    supd(1, 1, n, x, y, 0);
                    break;
                }
                case 2: {
                    gupd(1, 1, n, x, y, 0);
                    supd(1, 1, n, x, y, 1);
                    break;
                }
                default: {
                    gupd(1, 1, n, x, y, 1);
                    supd(1, 1, n, x, y, 0);
                }
            }
        }
        int sc = squery(1, 1, n, 1, n), gc = gquery(1, 1, n, 1, n), bc = n - gc - sc;
        cout << "Case " << i << ": The total value of the hook is " << bc + sc * 2 + gc * 3 << '.' << endl;
    }
    return 0;
}
