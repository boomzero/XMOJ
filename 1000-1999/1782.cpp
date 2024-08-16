#include <bits/stdc++.h>

using namespace std;
int nxt[10000005];

void get_next(string b) {
    nxt[0] = -1;
    int k = -1, j = 0;
    while (j < b.length()) {
        if (k == -1 || b[j] == b[k]) {
            nxt[++j] = ++k;
        } else {
            k = nxt[k];
        }
    }
}

set<int> match;

void kmp(string a, string b) {
    int i = 0, j = 0;
    while (i < a.length()) {
        if (j == -1 || a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (j == b.length()) {
                match.insert(i - b.length() + 1);
                i += b.length();
            } else
                j = nxt[j];
        }
        if (j == b.length())
            match.insert(i - b.length() + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    string s1;
    while (true) {
        cin >> s1;
        if (s1 == ".") break;
        get_next(s1);
        if (s1.length() % (s1.length() - nxt[s1.length()]) != 0) {
            cout << 1 << endl;
        } else {
            cout << s1.length() / (s1.length() - nxt[s1.length()]) << endl;
        }
//        for (int i = 1; i <= s2.length(); i++) {
//            clog << nxt[i] << " ";
//        }
    }
    return 0;
}
