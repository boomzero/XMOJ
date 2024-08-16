#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("capslock.in", "r", stdin);
    freopen("capslock.out", "w", stdout);
    string s;
    cin >> s;
    for (char i: s) {
        if (isupper(i)) {
            putchar(tolower(i));
        }
        else if (islower(i)) {
            putchar(toupper(i));
        }
        else {
            putchar(i);
        }
    }
    putchar('\n');
    return 0;
}
