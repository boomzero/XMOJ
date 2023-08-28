#include <bits/stdc++.h>

using namespace std;
int n, m[150] = {0};
double cm = 100;
bool cc = false; //fd, tm

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }
    for (int i = 1; i < n; i++) {
        if (cc) {
            if (m[i] < m[i + 1]) {
                cc = false;
                cm = cm / (double) m[i] * 100;
            }
        } else {
            if (m[i] > m[i + 1]) {
                cc = true;
                cm = cm / 100 * m[i];
            }
        }
    }
    if (cc) {
        cc = false;
        cm = cm / (double) m[n] * 100;
    }
    printf("%.2f", cm);
    return 0;
}


