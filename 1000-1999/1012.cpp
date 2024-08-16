#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int mxl = 2 * n + 1;
    for (int i = 1; i <= n + 1; ++i) {
        int dc = i, hc = dc - 1, tc = dc + hc;
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        bool f = true;
        for (int j = 1; j <= dc; ++j) {
            if (!f) cout << '-';
            f = false;
            cout << '$';
        }
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        cout << ' ';
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        f = true;
        for (int j = 1; j <= dc; ++j) {
            if (!f) cout << '-';
            f = false;
            cout << '$';
        }
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        cout << endl;
    }
    for (int i = n + 2; i <= 2 * n + 1; ++i) {
        int dc = n + 1 - (i - n - 1), hc = dc - 1, tc = dc + hc;
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        bool f = true;
        for (int j = 1; j <= dc; ++j) {
            if (!f) cout << '-';
            f = false;
            cout << '$';
        }
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        cout << ' ';
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        f = true;
        for (int j = 1; j <= dc; ++j) {
            if (!f) cout << '-';
            f = false;
            cout << '$';
        }
        for (int j = 1; j <= (mxl - tc) / 2; ++j) {
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}

/*
   $       $
  $-$     $-$
 $-$-$   $-$-$
$-$-$-$ $-$-$-$
 $-$-$   $-$-$
  $-$     $-$
   $       $

 */
