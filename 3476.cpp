#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int a[4] = {0};
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3, cmp);
    cout << a[0] - a[2] << endl;
    return 0;
}
