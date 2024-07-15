#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100005;
int root, tot;
int v[MAXN];
unsigned int w[MAXN];
int c[MAXN], s[MAXN];
int lc[MAXN], rc[MAXN];
mt19937 rng(time(nullptr)); // NOLINT(*-msc51-cpp)

int new_node(int val) {
    tot++;
    v[tot] = val;
    w[tot] = rng();
    lc[tot] = rc[tot] = 0;
    c[tot] = s[tot] = 1;
    return tot;
}

void upd(int k) {
    s[k] = c[k] + s[lc[k]] + s[rc[k]];
}

void lturn(int &k) {
    int tmp = rc[k];
    rc[k] = lc[tmp];
    lc[tmp] = k;
    s[tmp] = s[k];
    upd(k);
    k = tmp;
}

void rturn(int &k) {
    int tmp = lc[k];
    lc[k] = rc[tmp];
    rc[tmp] = k;
    s[tmp] = s[k];
    upd(k);
    k = tmp;
}

void insert(int &k, int val) { // NOLINT(*-no-recursion)
    if (k == 0) {
        k = new_node(val);
        return;
    }
    s[k]++;
    if (v[k] == val) {
        c[k]++;
        return;
    }
    if (val > v[k]) {
        insert(rc[k], val);
        if (w[k] > w[rc[k]]) {
            lturn(k);
        }
    } else {
        insert(lc[k], val);
        if (w[k] > w[rc[k]]) {
            rturn(k);
        }
    }
}

void del(int &k, int val) { // NOLINT(*-no-recursion)
    if (k == 0) {
        throw runtime_error("del");
    }
    if (v[k] == val) {
        if (c[k] > 1) {
            c[k]--;
            s[k]--;
        } else if (lc[k] == 0 || rc[k] == 0) {
            k = lc[k] + rc[k];
        } else {
            if (w[lc[k]] > w[rc[k]]) {
                lturn(k);
            } else {
                rturn(k);
            }
            del(k, val);
        }
    } else {
        s[k]--;
        if (val > v[k]) {
            del(rc[k], val);
        } else {
            del(lc[k], val);
        }
    }
}

int query_rank(int k, int val) { // NOLINT(*-no-recursion)
    if (k == 0) return 0;
    if (v[k] == val) {
        return s[lc[k]] + 1;
    }
    if (v[k] > val) {
        return query_rank(lc[k], val);
    }
    return query_rank(rc[k], val) + c[k] + s[lc[k]];
}

int query_nth(int k, int n) { // NOLINT(*-no-recursion)
    if (k == 0) return 0;
    if (n <= s[lc[k]]) {
        return query_nth(lc[k], n);
    }
    if (n > s[lc[k]] + c[k]) {
        return query_nth(rc[k], n - s[lc[k]] - c[k]);
    }
    return v[k];
}

int ans;

void query_pre(int k, int n) { // NOLINT(*-no-recursion)
    if (k == 0) return;
    if (v[k] < n) {
        ans = v[k];
        query_pre(rc[k], n);
    } else {
        query_pre(lc[k], n);
    }
}

int pre(int n) {
    query_pre(root, n);
    return ans;
}

void query_nxt(int k, int n) { // NOLINT(*-no-recursion)
    if (k == 0) return;
    if (v[k] > n) {
        ans = v[k];
        query_nxt(lc[k], n);
    } else {
        query_nxt(rc[k], n);
    }
}

int nxt(int n) {
    query_nxt(root, n);
    return ans;
}


int main() {
    int n;
    scanf("%d", &n); // NOLINT(*-err34-c)
    for (int i = 1; i <= n; i++) {
        int op, x;
        scanf("%d%d", &op, &x); // NOLINT(*-err34-c)
        switch (op) {
            case 1:
                insert(root, x);
                break;
            case 2:
                del(root, x);
                break;
            case 3:
                printf("%d\n", query_rank(root, x));
                break;
            case 4:
                printf("%d\n", query_nth(root, x));
                break;
            case 5:
                printf("%d\n", pre(x));
                break;
            default:
                printf("%d\n", nxt(x));
        }
    }
    return 0;
}
