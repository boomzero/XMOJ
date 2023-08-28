#include <bits/stdc++.h>

using namespace std;
typedef vector<int> num;

void upd(num &in, int conv) {
    for (int i = 0; i < in.size(); i++) {
        if (in[i] >= conv) {
            if (i + 1 == in.size()) {
                in.resize(in.size() + 1);
            }
            in[i + 1] += in[i] / conv;
            in[i] %= conv;
        }
    }
}

num add(num a, num b, int conv) {
    num ans;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (a.size() > b.size()) {
            if (b.size() - 1 < i) {
                ans.push_back(a[i]);
            } else {
                ans.push_back(a[i] + b[i]);
            }
        } else {
            if (a.size() - 1 < i) {
                ans.push_back(b[i]);
            } else {
                ans.push_back(a[i] + b[i]);
            }
        }
    }
    upd(ans, conv);
    return ans;
}

num init() {
    num n;
    n.push_back(0);
    return n;
}

void print(num in) {
    for (int i = in.size() - 1; i >= 0; i--) {
        if (in[i] > 9) {
            cout << char(in[i] - 10 + 'A');
        } else {
            cout << in[i];
        }
    }
}

num input(int conv) {
    num n;
    string in;
    cin >> in;
    for (int i = in.size() - 1; i >= 0; i--) {
        if (isalpha(in[i])) {
            n.push_back(in[i] - 'A' + 10);
        } else {
            n.push_back(in[i] - '0');
        }
    }
    upd(n, conv);
    return n;
}

num rev(num in) {
    reverse(in.begin(), in.end());
    return in;
}

bool isRev(num in) {
    return rev(in) == in;
}

int main() {
    int n;
    cin >> n;
    num m = input(n);
    if (isRev(m)) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= 30; ++i) {
        num p = rev(m);
        if (isRev(add(m, p, n))) {
            cout << i << endl;
            return 0;
        }
        m = add(m, p, n);
    }
    cout << "Impossible" << endl;
    return 0;
}
