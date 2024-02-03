#include <bits/stdc++.h>

using namespace std;

struct node {
    node *lc = nullptr, *rc = nullptr, *fa = nullptr; ///in the case of !, the value is stored in lc
    bool isOp = false;
    int id = 0;
    bool rubbish = false;

/*
 * &: 1
 * |: 2
 * !: 3
 */
    explicit node(int id, bool isOp = false) : isOp(isOp), id(id) {}
} *st[100005];

int stackSize = 0, val[100005];
map<int, node *> var;

node *stop() {
    return st[stackSize];
}

void spush(node *i) {
    st[++stackSize] = i;
}

void spop() {
    st[stackSize] = nullptr; //for better debugging
    stackSize--;
}

/*
 * &: 1
 * |: 2
 * !: 3
 */
int calc(node *head) {
    if (!head->isOp) {
        return val[head->id];
    }
    if (head->id == 1) { // &
        int l = calc(head->lc), r = calc(head->rc);
        if (l == 0) {
            head->rc->rubbish = true;
        }
        if (r == 0) {
            head->lc->rubbish = true;
        }
        return l && r;
    }
    if (head->id == 2) { // |
        int l = calc(head->lc), r = calc(head->rc);
        if (l == 1) {
            head->rc->rubbish = true;
        }
        if (r == 1) {
            head->lc->rubbish = true;
        }
        return l || r;
    }
    if (head->id == 3) { // !
        int l = calc(head->lc);
        return !l;
    }
    return 0;
}

int main() {
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "w", stdout);
    node *head = nullptr;
    string a;
    getline(cin, a);
    a.push_back(' '); //normalize
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == 'x') {
            string tmp;
            while (a[i + 1] != ' ') {
                i++;
                tmp.push_back(a[i]);
            }
            node *nn = new node(stoi(tmp));
            var[stoi(tmp)] = nn;
            spush(nn);
        } else if (a[i] == '!') {
            node *nn = new node(3, true);
            nn->lc = stop();
            spop();
            nn->lc->fa = nn;
            spush(nn);
        } else if (a[i] == '&' || a[i] == '|') {
            node *nn = new node(a[i] == '&' ? 1 : 2, true);
            nn->lc = stop();
            spop();
            nn->lc->fa = nn;
            nn->rc = stop();
            spop();
            nn->rc->fa = nn;
            spush(nn);
        }
    }
    head = stop();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    int initAns = calc(head), q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int id;
        cin >> id;
        node *c = var[id];
        bool rubbish = false;
        while (c->fa != nullptr) {
            if (c->rubbish) {
                rubbish = true;
                break;
            }
            c = c->fa;
        }
        cout << (rubbish == initAns) << endl;
    }
    return 0;
}

