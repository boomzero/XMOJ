#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    string in;
    cin >> in;
    bool ac = true;
    if (in[0] != 'A') ac = false;
    int cCnt = 0;
    int p = -1;
    for (char i: in) {
        p++;
        if (i == 'C' && p != 1 && p != in.length() - 1) cCnt++;
        else if (isupper(i) && p != 0) ac = false;
    }
    if (cCnt != 1) ac = false;
    if (ac) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}

