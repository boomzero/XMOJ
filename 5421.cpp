#include <bits/stdc++.h>

using namespace std;

string flip(string in, int nf) {
    int p = 0;
    for (char &i: in) {
        p++;
        if (p != nf) {
            if (i == '1') {
                i = '0';
            } else {
                i = '1';
            }
        }
    }
    return in;
}

int main() {
    int n;
    cin >> n;
    string coin;
    for (int i = 0; i < n; ++i) {
        coin.push_back('0');
    }
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        coin = flip(coin, i);
        cout << coin << endl;
    }
    return 0;
}

