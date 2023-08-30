#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int tot = k, curr = 0;
    double ans[6] = {0}, cl = n;
    int cp = 1;
    while (curr < tot) {
        for (int i = 1; i <= 4; ++i) {
            ans[cp] += cl;
            cp++;
            if (cp > 3) cp = 1;
        }
        curr++;
        cl *= sqrt(2) / 2.0;
    }
    printf("%.3f %.3f %.3f\n", ans[1], ans[2], ans[3]);
    return 0;
}
